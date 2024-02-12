#include "MainComponent.h"
#include "wtypes.h"
#include <iostream>
using namespace std;

//==============================================================================
MainComponent::MainComponent() :
    fileBrowser(juce::FileBrowserComponent::openMode |
    juce::FileBrowserComponent::canSelectFiles
    , juce::File("C:/"), NULL, NULL),

    menuBar(nullptr),

    controls()
{
    GetDesktopResolution(x, y);
    setSize (x,y);

    // Components adding
    addAndMakeVisible(fileBrowser);
    addAndMakeVisible(menuBar);
    addAndMakeVisible(controls);
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

    g.setFont (juce::Font (16.0f));
    g.setColour (juce::Colours::white);
}

void MainComponent::resized()
{

    menuBar.setBounds(getX(), // X position reletive to main component
        getY(), // Y position reletive to main component
        getWidth(), // Width of component
        getHeight() * 0.025); // Height if component

    fileBrowser.setBounds(getWidth() * 0.7, // X position reletive to main component
                          getHeight() * 0.025, // Y position reletive to main component
                          getWidth() * 0.3, // Width of component
                          getHeight() * 0.3); // Height if component

    controls.setBounds(getWidth() * 0.5, // X position reletive to main component
            getHeight() * 0.025, // Y position reletive to main component
            getWidth() * 0.15, // Width of component
            getHeight() * 0.05);

}

