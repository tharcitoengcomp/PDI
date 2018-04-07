#include <iostream>
#include <opencv2/opencv.hpp>
#include <cv.h>
#include <highgui.h>

using namespace cv;
using namespace std;

int main(int, char**){
  Mat image;

  int v1[2], v2[2];

  image= imread("naruto.jpg",CV_LOAD_IMAGE_GRAYSCALE);
  if(!image.data)
    cout << "erro!!! Não foi posivel carregar a imagem" << endl;

  cout << "Informe as cordenadas inciais do ponto 1" << endl;
  cin >> v1[0] >> v1[1];
  
  cout << "Informe o fim das cordenadas do ponto 2" << endl;
  cin >> v2[0] >> v2[1];

  //Negativo da Imagem 
  for(int i=v1[0];i<v2[0];i++){
    for(int j=v1[1];j<v2[1];j++){
      image.at<uchar>(i,j)= 255 - image.at<uchar>(i,j);
    }
  }

  imshow("janela", image);
  
  waitKey();
  return 0;
}
