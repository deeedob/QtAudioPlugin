#include "plugin_view.h"
#include <QSlider>
#include <QLabel>
#include <QHBoxLayout>

PluginView::PluginView(Steinberg::Vst::EditController *controller, Steinberg::ViewRect *size)
    : QVstEditorView(controller,size)
{ }


QLayout *PluginView::createLayout()
{
    QHBoxLayout* layout = new QHBoxLayout();
    QSlider slider(Qt::Orientation::Horizontal);
    QLabel label("Hello World!");

    layout->addWidget(&slider);
    layout->addWidget(&label);

    return layout;
}
