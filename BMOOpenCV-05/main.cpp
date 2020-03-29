//
//  main.cpp
//  BMOOpenCV-05
//
//  Created by Breno Medeiros on 29/03/20.
//  Copyright © 2020 ProgramasBMO. All rights reserved.
//

#include <opencv2/opencv.hpp>

using namespace cv;

int main(int argc, const char * argv[]) {
    // insert code here...
    String caminho = "/Users/brenomedeiros/Documents/ProgramasBMO/Cpp/BMOOpenCV-05/BMOOpenCV-05/";
    String caminhoImagens = "/Users/brenomedeiros/Documents/ProgramasBMO/Cpp/BMOOpenCV-05/BMOOpenCV-05/Images/";
    
    Mat original = imread(caminhoImagens+"Me.jpeg", CV_LOAD_IMAGE_COLOR);
    
    Mat canaisDivididos[3];
    split(original, canaisDivididos);
    
    namedWindow("Azul", CV_WINDOW_AUTOSIZE);
    imshow("Azul", canaisDivididos[0]);
    moveWindow("Azul", 0*(original.cols/2), 1080);
    namedWindow("Verde", CV_WINDOW_AUTOSIZE);
    imshow("Verde", canaisDivididos[1]);
    moveWindow("Verde", 1*(original.cols/2), 1080);
    namedWindow("Vermelho", CV_WINDOW_AUTOSIZE);
    imshow("Vermelho", canaisDivididos[2]);
    moveWindow("Vermelho", 2*(original.cols/2), 1080);
    
    //Substitui("apaga") a matriz do Vermelho pro uma de mesma dimensao e tamanho de pixel.
    canaisDivididos[2] = Mat::zeros(canaisDivididos[2].size(), CV_8UC1);
    Mat saida;
    merge(canaisDivididos, 3, saida);
    
    imshow("Saida", saida);
    
    waitKey();
    

    return 0;
}
