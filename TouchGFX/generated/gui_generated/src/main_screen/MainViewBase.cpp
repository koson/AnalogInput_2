/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/main_screen/MainViewBase.hpp>
#include <touchgfx/Color.hpp>
#include "BitmapDatabase.hpp"
#include <texts/TextKeysAndLanguages.hpp>

MainViewBase::MainViewBase() :
    sliderValueChangedCallback(this, &MainViewBase::sliderValueChangedCallbackHandler)
{

    touchgfx::CanvasWidgetRenderer::setupBuffer(canvasBuffer, CANVAS_BUFFER_SIZE);

    __background.setPosition(0, 0, 480, 272);
    __background.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));

    background.setXY(0, 0);
    background.setBitmap(touchgfx::Bitmap(BITMAP_BLUE_BACKGROUNDS_MAIN_BG_480X272PX_ID));

    graphBackground.setPosition(15, 47, 389, 201);
    graphBackground.setColor(touchgfx::Color::getColorFrom24BitRGB(250, 248, 192));
    graphBackground.setBorderColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));
    graphBackground.setBorderSize(1);

    graph.setScale(1);
    graph.setGraphRangeX(0, 255);
    graph.setPosition(15, 47, 389, 201);
    graph.setGraphAreaMargin(10, 28, 19, 22);
    graph.setGraphAreaPadding(2, 6, 0, 6);
    graph.setGraphRangeY(0, 1024);

    graphMajorXAxisGrid.setScale(1);
    graphMajorXAxisGrid.setColor(touchgfx::Color::getColorFrom24BitRGB(20, 151, 197));
    graphMajorXAxisGrid.setInterval(20);
    graphMajorXAxisGrid.setLineWidth(1);
    graphMajorXAxisGrid.setAlpha(80);
    graph.addGraphElement(graphMajorXAxisGrid);

    graphMajorYAxisGrid.setScale(1);
    graphMajorYAxisGrid.setColor(touchgfx::Color::getColorFrom24BitRGB(20, 151, 197));
    graphMajorYAxisGrid.setInterval(102);
    graphMajorYAxisGrid.setLineWidth(1);
    graph.addGraphElement(graphMajorYAxisGrid);

    graphMajorXAxisLabel.setScale(1);
    graphMajorXAxisLabel.setInterval(50);
    graphMajorXAxisLabel.setLabelTypedText(touchgfx::TypedText(T_SINGLEUSEID7));
    graphMajorXAxisLabel.setColor(touchgfx::Color::getColorFrom24BitRGB(20, 151, 197));
    graph.addBottomElement(graphMajorXAxisLabel);

    graphMajorYAxisLabel.setScale(1);
    graphMajorYAxisLabel.setInterval(200);
    graphMajorYAxisLabel.setLabelTypedText(touchgfx::TypedText(T_SINGLEUSEID8));
    graphMajorYAxisLabel.setColor(touchgfx::Color::getColorFrom24BitRGB(20, 151, 197));
    graph.addLeftElement(graphMajorYAxisLabel);

    graphLine1.setScale(1);
    graphLine1Painter.setColor(touchgfx::Color::getColorFrom24BitRGB(56, 122, 78));
    graphLine1.setPainter(graphLine1Painter);
    graphLine1.setLineWidth(2);
    graph.addGraphElement(graphLine1);

    sliderResolution.setXY(423, 47);
    sliderResolution.setBitmaps(touchgfx::Bitmap(BITMAP_BLUE_SLIDER_VERTICAL_SMALL_SLIDER3_VERTICAL_ROUND_BACK_ID), touchgfx::Bitmap(BITMAP_BLUE_SLIDER_VERTICAL_SMALL_SLIDER3_VERTICAL_ROUND_FILL_ID), touchgfx::Bitmap(BITMAP_BLUE_SLIDER_VERTICAL_SMALL_INDICATORS_SLIDER3_VERTICAL_ROUND_NOB_ID));
    sliderResolution.setupVerticalSlider(7, 3, 0, 0, 125);
    sliderResolution.setValueRange(20, 1024);
    sliderResolution.setValue(1024);
    sliderResolution.setNewValueCallback(sliderValueChangedCallback);

    textArea1.setPosition(161, 14, 243, 25);
    textArea1.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));
    textArea1.setLinespacing(0);
    Unicode::snprintf(textArea1Buffer, TEXTAREA1_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID6).getText());
    textArea1.setWildcard(textArea1Buffer);
    textArea1.setTypedText(touchgfx::TypedText(T_SINGLEUSEID5));

    add(__background);
    add(background);
    add(graphBackground);
    add(graph);
    add(sliderResolution);
    add(textArea1);
}

void MainViewBase::setupScreen()
{

}

void MainViewBase::sliderValueChangedCallbackHandler(const touchgfx::Slider& src, int value)
{
    if (&src == &sliderResolution)
    {
        //SliderValueChanged
        //When sliderResolution value changed call virtual function
        //Call sliderValueChanged
        sliderValueChanged(value);
    }
}
