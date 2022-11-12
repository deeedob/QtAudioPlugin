#ifndef QVSTEDITORVIEW_H
#define QVSTEDITORVIEW_H

#include <public.sdk/source/vst/vsteditcontroller.h>

class QWidget;
class QLayout;
class QVstParameterContainer;

class QVstEditorView : public Steinberg::Vst::EditorView
{
public:
    QVstEditorView(Steinberg::Vst::EditController* controller, Steinberg::ViewRect* size = nullptr);
    ~QVstEditorView() override;

    Steinberg::tresult isPlatformTypeSupported(Steinberg::FIDString type) override;
    Steinberg::tresult attached(void *parent, Steinberg::FIDString type) override;
    Steinberg::tresult removed() override;
    Steinberg::tresult getSize(Steinberg::ViewRect *size) override;
    Steinberg::tresult onSize(Steinberg::ViewRect *newSize) override;
    Steinberg::tresult canResize() override;
    Steinberg::tresult checkSizeConstraint(Steinberg::ViewRect *rect) override;

    QVstParameterContainer* parameter() const { return m_paramContainer; }
protected:
    virtual QLayout* createLayout();
private:
    QWidget* m_hostedWidget;
    QVstParameterContainer* m_paramContainer;
    //QVstHostedWidget* m_hostedWidget;
};


#endif
