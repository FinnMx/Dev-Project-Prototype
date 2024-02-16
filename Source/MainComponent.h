#pragma once

#include <JuceHeader.h>
#include <DelayComponent.h>
#include <InputComponent.h>
#include <KillEQComponent.h>
#include <MasterComponent.h>
#include <ReverbComponent.h>
#include <TrackThumbnailComponent.h>
#include <TenBandComponent.h>

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

    //look and feel

    // Child components
    juce::MenuBarComponent menuBar;

    juce::Rectangle<int> test;
    juce::TextButton testButton;

    DelayComponent delayComponent;
    InputComponent inputComponent;
    KillEQComponent killEQComponent;
    MasterComponent masterComponent;
    ReverbComponent reverbComponent;
    TrackThumbnailComponent trackThumbnailComponent;
    TenBandComponent tenBandComponent;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
