/*
  ==============================================================================

    InputComponent.h
    Created: 15 Feb 2024 9:33:49pm
    Author:  Finn

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
*/
class InputComponent  : public juce::Component
{
public:
    InputComponent();
    ~InputComponent() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    // --------------------------
    // Track A objects

    juce::TextButton trackALoad;
    juce::TextButton trackAPlay;
    juce::TextButton trackAPause;
    juce::TextButton trackAStop;

    // --------------------------
    // Track B objects

    juce::TextButton trackBLoad;
    juce::TextButton trackBPlay;
    juce::TextButton trackBPause;
    juce::TextButton trackBStop;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (InputComponent)
};
