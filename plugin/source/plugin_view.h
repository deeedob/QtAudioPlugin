#pragma once

#include <qvsteditorview.h>

class PluginView : public QVstEditorView
{
public:
    explicit PluginView(Steinberg::Vst::EditController* controller, Steinberg::ViewRect* size = nullptr);
    ~PluginView() override = default;

protected:
    QLayout* createLayout() override;
private:
};