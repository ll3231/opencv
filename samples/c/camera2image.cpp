#include<highgui.h>
#include</usr/include/boost/predef/os/windows.h>
#include<stdio.h>
int main ()
{
        CvCapture *capture=cvCreateCameraCapture(0);
        cvNamedWindow("camera",CV_WINDOW_AUTOSIZE);
        IplImage *image;
        char file_name[15];
        int i;
        double fps = cvGetCaptureProperty(capture, CV_CAP_PROP_FPS);
	printf("fps=%lf",fps);
        while(1)
        {
                for(i=0;i<100;i++)
                {
                        image=cvQueryFrame(capture);
                        if(!image)
                                break;
                        cvShowImage("camera",image);
                        char c=cvWaitKey(20);
                        if(c==27)
                        {
                                cvReleaseCapture(&capture);
                                cvDestroyWindow("hh");
                                exit(0);
                         }//按esc退出

                        sprintf(file_name,"%05d.jpg",i);//目录下生成
                        cvSaveImage(file_name,image);

                }

        }

}
