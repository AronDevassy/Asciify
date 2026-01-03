#include<iostream>
#define STB_IMAGE_IMPLEMENTATION
#include <stb/stb_image.h>
#include <filesystem>
#include <vector>
using namespace std;
namespace fs = std::filesystem;
int width,height,channels;


string levels = " .:-=+*#%@█";
string userinput;


vector<string> getImagePaths(){
    vector<string> paths;
    for(const auto&entry : fs::directory_iterator("images")){
        const fs::path e = entry.path().extension();
        if(e == ".png" || e == ".jpg" || e == ".jpeg",".bmp"){
        paths.push_back(entry.path().string());
        //cout<<entry.path()<<endl;
    }
}
    return paths;
}


void RenderImage(){
vector<string> imagePaths = getImagePaths();
for(const auto&path:imagePaths){
unsigned char *image = stbi_load(path.c_str(),&width,&height, &channels,1);


for(int y = 0;y<height;y++){
for (int x= 0;x<width;x++){
    if (x==0){
        cout<<"\n";
    }
    int index = (y * width + x);
    unsigned char pixel = image[index];
    int brightness = pixel *(levels.size()-1)/255;
    cout<<levels[brightness]<<" ";
   

}

}
cout<<"\n\n\n";
}

}

int main(){
    RenderImage();
    cin>>userinput;
    return 0;
}

