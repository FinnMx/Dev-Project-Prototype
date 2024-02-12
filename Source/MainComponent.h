#pragma once

#include <JuceHeader.h>
#include <ControlComponent.h>

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainComponent  : public juce::Component
{
public:
    //==============================================================================
    MainComponent();
    ~MainComponent() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;
    void GetDesktopResolution(int& horizontal, int& vertical);

private:
    //==============================================================================
    // Your private member variables go here...
    int x, y;

    // Child components
    juce::FileBrowserComponent fileBrowser;
    juce::MenuBarComponent menuBar;
    ControlComponent controls;


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
