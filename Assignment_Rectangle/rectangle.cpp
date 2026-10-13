#include <iostream>
using namespace std;

class Rectangle{
    private:
    double width;
    double length;

    public:
    //setting the width and length of the rectangle with validation
    void setWidth(double w){
        if(w>0){
            width = w;
        }
        else{
        cout<<"Invalid width! Must be greater than 0.\n";
        }
    }

    void setLength(double l){
        if(l>0){
            length = l;
        }
        else{
            cout<<"Invalid length! Must be greater than 0.\n";
        }
    }

    //getting the width and length of the rectangle
    double getWidth(){
        return width;
    }
    double getLength(){
        return length;
    }

    //calculation fuctions for the area and perimeter of the rectangle

    double calculateArea() {
        return width*length;
    }

    double calculatePerimeter() {
        return 2*(width+length);
    }
};

int main(){

    Rectangle rectangle1;
    rectangle1.setWidth(5.3);
    rectangle1.setLength(7.6);

    cout<<"First Rectangle"<<"\n";
    cout<<"Width: "<<rectangle1.getWidth() << "\n";
    cout<<"Length: "<<rectangle1.getLength() << "\n";
    cout<<"Area: "<< rectangle1.calculateArea() <<"\n";
    cout<<"Perimeter: "<< rectangle1.calculatePerimeter() <<"\n";

    Rectangle rectangle2;
    rectangle2.setWidth(4.5);
    rectangle2.setLength(8.0);

    cout<<"Second Rectangle"<<"\n";
    cout<<"Width: "<<rectangle2.getWidth() << "\n";
    cout<<"Length: "<<rectangle2.getLength() << "\n";
    cout<<"Area: "<< rectangle2.calculateArea() <<"\n";
    cout<<"Perimeter: "<< rectangle2.calculatePerimeter() <<"\n";

return 0;
}