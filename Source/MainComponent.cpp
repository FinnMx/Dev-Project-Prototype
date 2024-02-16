#include "MainComponent.h"
#include "wtypes.h"
#include <iostream>
using namespace std;

//==============================================================================
MainComponent::MainComponent() :
    menuBar(nullptr),
    test(),
    testButton("hello")

{
    GetDesktopResolution(x, y);
    setSize (x,y);

    auto* lf = dynamic_cast<juce::LookAndFeel_V4*>(&getLookAndFeel());
    lf->setColourScheme({
             0xff535A62, 0xff403C43, 0xff232027,
             0xff535A62, 0xffffffff, 0xff42a2c8,
             0xffffffff, 0xff181f22, 0xffffffff
        });

    // Components adding
    addAndMakeVisible(testButton);

    addAndMakeVisible(menuBar);
    addAndMakeVisible(masterComponent);
    addAndMakeVisible(trackThumbnailComponent);
    addAndMakeVisible(tenBandComponent);
    addAndMakeVisible(reverbComponent);
    addAndMakeVisible(delayComponent);
    addAndMakeVisible(killEQComponent);

}

MainComponent::~MainComponent()
{
}

// Get the horizontal and vertical screen sizes in pixel
void MainComponent::GetDesktopResolution(int& horizontal, int& vertical)
{
    RECT desktop;
    // Get a handle to the desktop window
    const HWND hDesktop = GetDesktopWindow();
    // Get the size of screen to the variable desktop
    GetWindowRect(hDesktop, &desktop);
    // The top left corner will have coordinates (0,0)
    // and the bottom right corner will have coordinates
    // (horizontal, vertical)
    horizontal = desktop.right;
    vertical = desktop.bottom;
}

//==============================================================================
void MainComponent::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll(getLookAndFeel().findColour(juce::Toolbar::backgroundColourId));

    g.setFont (juce::Font (16.0f));
    g.setColour (juce::Colours::white);

    g.setColour(juce::Colours::red);
    g.drawRect(test);
    g.fillRect(test);
}

void MainComponent::resized()
{
    test.setBounds(getX(),
        getHeight() * 0.035,
        getWidth() * 0.25,
        getHeight() * 0.35
    );

    testButton.setBounds(getWidth() * 0.1,
        getHeight() * 0.1,
        getWidth() * 0.1,
        getHeight() * 0.1
    );

    menuBar.setBounds(getX(), // X position reletive to main component
        getY(), // Y position reletive to main component
        getWidth(), // Width of component
        getHeight() * 0.025); // Height of component

    //-----------------------------------------------
    //Top Rack

    inputComponent.setBounds(
        getX(),
        getHeight() * 0.035, 
        getWidth() * 0.25, 
        getHeight() * 0.35
    ); 

    masterComponent.setBounds(
        getWidth() * 0.25,
        getHeight() * 0.035,
        getWidth() * 0.15,
        getHeight() * 0.35
    );

    trackThumbnailComponent.setBounds(
        getWidth() * 0.4,
        getHeight() * 0.035,
        getWidth() * 0.375,
        getHeight() * 0.35
    );

    tenBandComponent.setBounds(
        getWidth() * 0.775,
        getHeight() * 0.035,
        getWidth() * 0.225,
        getHeight() * 0.35
    );

    //-----------------------------------------------
    //Middle Rack's

    reverbComponent.setBounds(
        getX(),
        getHeight() * 0.39,
        getWidth(),
        getHeight() * 0.125
    );

    delayComponent.setBounds(
        getX(),
        getHeight() * 0.52,
        getWidth(),
        getHeight() * 0.125
    );


    //-----------------------------------------------
    //Bottom Rack

    killEQComponent.setBounds(
        getX(),
        getHeight() * 0.65,
        getWidth(),
        getHeight() * 0.28
    );
}

