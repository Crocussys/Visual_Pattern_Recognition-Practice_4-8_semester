#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

int main()
{
    Mat img = imread("../Visual_Pattern_Recognition-Practice_4-8_semester/image.jpg", IMREAD_COLOR);
    if (img.empty()){
        cout << "Изображение не загружено" << endl;
        return -1;
    }
    namedWindow("Original", WINDOW_NORMAL);
    imshow("Original", img);
    Mat new_img;
    Mat edges;
    Mat res;
    GaussianBlur(img, new_img, Size(0, 0), 2);
    cvtColor(new_img, new_img, COLOR_BGR2GRAY);
    namedWindow("Processed", WINDOW_NORMAL);
    imshow("Processed", new_img);
    Canny(new_img, edges, 0, 100);
    namedWindow("Edges", WINDOW_NORMAL);
    imshow("Edges", edges);
    vector<vector<Point> > contours;
    vector<Vec4i> hierarchy;
    findContours( edges, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE );
    for( size_t i = 0; i< contours.size(); i++ )
    {
        drawContours( img, contours, (int)i, Scalar(0, 255, 0), 1, LINE_8, hierarchy, 0 );
    }
    namedWindow("Contours", WINDOW_NORMAL);
    imshow( "Contours", img);
    waitKey(0);
    return 0;
}
