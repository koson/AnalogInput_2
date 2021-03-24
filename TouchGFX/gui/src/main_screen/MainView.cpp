#include <gui/main_screen/MainView.hpp>
#include <math.h>
#include <stdlib.h>

static uint16_t randomish(int32_t seed)
{
    static uint16_t last = 0;
    const uint16_t num = (seed * (1337 + last)) % 0xFFFF;
    last = num;
    return num;
}

MainView::MainView()
{
    tickCounter = 0;
}

void MainView::setupScreen()
{
    MainViewBase::setupScreen();

    // Initialize graph range with default slider value at start up
    sliderValueChanged(sliderResolution.getValue());
}

void MainView::tearDownScreen()
{
    MainViewBase::tearDownScreen();
}

void MainView::handleTickEvent()
{
    tickCounter++;

    // Insert each second tick
    if (tickCounter % 2 == 0)
    {
        float yMax = graph.getGraphRangeYMaxAsFloat();

        // Insert "random" points along a sine wave
        graph.addDataPoint((int)((sinf(tickCounter * .02f) + 1) * (yMax / 2.2f)) + randomish(tickCounter) % (int)(yMax / 10.f));
    }
}

void MainView::sliderValueChanged(int value)
{
    // Adjust the Y-axis max value according to the slider value
    graph.setGraphRangeY(0, value);
    graph.invalidate();

    // Adjust the interval of the labels/grid lines on the Y-axis
    // to match the new range.
    if (value > 199)
    {
        graphMajorYAxisLabel.setInterval(50);
        graphMajorYAxisGrid.setInterval(50);
    }
    else if (value > 100)
    {
        graphMajorYAxisLabel.setInterval(20);
        graphMajorYAxisGrid.setInterval(20);
    }
    else
    {
        graphMajorYAxisLabel.setInterval(10);
        graphMajorYAxisGrid.setInterval(10);
    }

    graphMajorYAxisLabel.invalidate();
    graphMajorYAxisGrid.invalidate();
}
