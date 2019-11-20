#include<iostream>
class Room{
    int width;
    int length;
  void setValue(int w, int l){
    width=w;
    length=l;
  }
};
int main(){
  Room objRoom;
  objRoom.width = 12;   
  return 0;

}