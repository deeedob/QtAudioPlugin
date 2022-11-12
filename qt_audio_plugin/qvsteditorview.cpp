#include <QWidget>
#include <QLayout>
#include "qvsteditorview.h"
#include "qvstparametercontainer.h"

QVstEditorView::QVstEditorView(Steinberg::Vst::EditController *controller, Steinberg::ViewRect *size)
    : Steinberg::Vst::EditorView(controller, size), m_hostedWidget(nullptr)
{
    m_paramContainer = new QVstParameterContainer(controller);
}

QVstEditorView::~QVstEditorView()
{
    delete m_hostedWidget;
    delete m_paramContainer;
}


Steinberg::tresult QVstEditorView::isPlatformTypeSupported(Steinberg::FIDString type)
{
    return Steinberg::kResultTrue;
}

Steinberg::tresult QVstEditorView::attached(void *parent, Steinberg::FIDString type)
{
    m_hostedWidget = new QWidget();
    QLayout* layout = createLayout();
    if (layout != nullptr) {
        m_hostedWidget->setLayout(layout);
        m_hostedWidget->updateGeometry();
    }
    return Steinberg::Vst::EditorView::attached(parent, type);
}

Steinberg::tresult QVstEditorView::removed()
{
    delete m_hostedWidget;
    m_hostedWidget = nullptr;
    return Steinberg::kResultOk;
}

Steinberg::tresult QVstEditorView::getSize(Steinberg::ViewRect *size)
{
    if (size == nullptr || m_hostedWidget == nullptr)
        return Steinberg::kResultFalse;

    auto rect = m_hostedWidget->geometry();
    size->top = rect.top();
    size->bottom = rect.bottom();
    size->left = rect.left();
    size->right = rect.right();

    return Steinberg::kResultOk;
}

Steinberg::tresult QVstEditorView::onSize(Steinberg::ViewRect *newSize)
{
    m_hostedWidget->resize(QSize(newSize->getWidth(), newSize->getHeight()));
    return Steinberg::kResultOk;
}

Steinberg::tresult QVstEditorView::canResize()
{
    return Steinberg::kResultOk;
}

Steinberg::tresult QVstEditorView::checkSizeConstraint(Steinberg::ViewRect *rect)
{
    if (rect == nullptr || m_hostedWidget == nullptr)
        return Steinberg::kResultFalse;

    if (rect->getWidth() < m_hostedWidget->minimumWidth())
        rect->right = rect->left + m_hostedWidget->minimumWidth();
    if (rect->getWidth() > m_hostedWidget->maximumWidth())
        rect->right = rect->left + m_hostedWidget->maximumWidth();
    if (rect->getHeight() < m_hostedWidget->minimumHeight())
        rect->bottom = rect->top + m_hostedWidget->minimumHeight();
    if (rect->getHeight() > m_hostedWidget->maximumHeight())
        rect->bottom = rect->top + m_hostedWidget->maximumHeight();

    return Steinberg::kResultOk;
}

QLayout *QVstEditorView::createLayout() {
    return nullptr;
}

