/*
  ==============================================================================

    InputComponent.cpp
    Created: 15 Feb 2024 9:33:49pm
    Author:  Finn

  ==============================================================================
*/

#include <JuceHeader.h>
#include "InputComponent.h"

//==============================================================================
InputComponent::InputComponent() : 
    trackALoad("^"),
    trackAPlay(">"),
    trackAPause("| |"),
    trackAStop("[]"),
    trackBLoad("^"),
    trackBPlay(">"),
    trackBPause("| |"),
    trackBStop("[]")
{
    addAndMakeVisible(trackALoad);
    addAndMakeVisible(trackAPlay);
    addAndMakeVisible(trackAPause);
    addAndMakeVisible(trackAStop);
    addAndMakeVisible(trackBLoad);
    addAndMakeVisible(trackBPlay);
    addAndMakeVisible(trackBPause);
    addAndMakeVisible(trackBStop);

}

InputComponent::~InputComponent()
{
}

void InputComponent::paint (juce::Graphics& g)
{

    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));   // clear the background

    g.setColour (getLookAndFeel().findColour(juce::TextEditor::outlineColourId).contrasting(0.15f));
    g.drawRect (getLocalBounds(), 1);   // draw an outline around the component

    g.setColour(juce::Colours::white);
    g.setFont(30.0f);
    g.drawText("Inputs", getLocalBounds(),
        juce::Justification::centredTop, true);
}

void InputComponent::resized()
{
    // ----------------------------------
    // TRACK A BOUNDS

    trackALoad.setBounds(
        getWidth() * 0.04,
        getHeight() * 0.175,
        getWidth() * 0.075,
        getHeight() * 0.1
    );

    trackAPlay.setBounds(
        getWidth() * 0.04,
        getHeight() * 0.3,
        getWidth() * 0.075,
        getHeight() * 0.1
    );

    trackAPause.setBounds(
        getWidth() * 0.04,
        getHeight() * 0.425,
        getWidth() * 0.075,
        getHeight() * 0.1
    );

    trackAStop.setBounds(
        getWidth() * 0.04,
        getHeight() * 0.55,
        getWidth() * 0.075,
        getHeight() * 0.1
    );

    // ---------------------------------
    // TRACK B BOUNDS

    trackBLoad.setBounds(
        getWidth() * 0.54,
        getHeight() * 0.175,
        getWidth() * 0.075,
        getHeight() * 0.1
    );

    trackBPlay.setBounds(
        getWidth() * 0.54,
        getHeight() * 0.3,
        getWidth() * 0.075,
        getHeight() * 0.1
    );

    trackBPause.setBounds(
        getWidth() * 0.54,
        getHeight() * 0.425,
        getWidth() * 0.075,
        getHeight() * 0.1
    );

    trackBStop.setBounds(
        getWidth() * 0.54,
        getHeight() * 0.55,
        getWidth() * 0.075,
        getHeight() * 0.1
    );

}
