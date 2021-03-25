#include <gui/main_screen/MainView.hpp>
#include <math.h>
#include <stdlib.h>
#include "string.h"

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
        float yMax = 1024;
//        float yMax = graph.getGraphRangeYMaxAsFloat();

        // Insert "random" points along a sine wave
//        graph.addDataPoint((int)((sinf(tickCounter * .02f) + 1) * (yMax / 2.2f)) + randomish(tickCounter) % (int)(yMax / 10.f));
        graph.addDataPoint((int)(adcValue*0.25));
    }
}

void MainView::sliderValueChanged(int value)
{
    // Adjust the Y-axis max value according to the slider value
    graph.setGraphRangeY(0, value);
    graph.invalidate();

    // Adjust the interval of the labels/grid lines on the Y-axis
    // to match the new range.
    graphMajorYAxisLabel.setInterval(250);
    graphMajorYAxisGrid.setInterval(250);

    if (value > 500)
    {
        graphMajorYAxisLabel.setInterval(100);
        graphMajorYAxisGrid.setInterval(100);
    }
    else if (value > 250)
    {
        graphMajorYAxisLabel.setInterval(50);
        graphMajorYAxisGrid.setInterval(50);
    }
    else if (value > 125)
    {
		graphMajorYAxisLabel.setInterval(25);
		graphMajorYAxisGrid.setInterval(25);
	}
    else if (value > 60)
    {
		graphMajorYAxisLabel.setInterval(15);
		graphMajorYAxisGrid.setInterval(15);
	}
    else {
        graphMajorYAxisLabel.setInterval(5);
        graphMajorYAxisGrid.setInterval(5);
    }


    graphMajorYAxisLabel.invalidate();
    graphMajorYAxisGrid.invalidate();
}

//    static const uint16_t TEXTAREA1_SIZE = 10;
//touchgfx::Unicode::UnicodeChar textArea1Buffer[TEXTAREA1_SIZE];


void MainView::analogUpdate(uint32_t value)
{
	memset(&textArea1Buffer, 0, TEXTAREA1_SIZE);
	Unicode::snprintfFloat(textArea1Buffer, sizeof(textArea1Buffer), "%.3f",
			value * 0.000805664); // 3.3/4096 = 0.000805664
	adcValue = value;
	textArea1.invalidate();
}
