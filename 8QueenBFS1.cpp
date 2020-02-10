#include<iostream>
#include <cstdlib>
using namespace std;
struct node{
    int arr[8][8];
    int row;
    int column;
    int gn=1;
    int fn;
    int hn;
    struct node *next;
};
void print(struct node *a){
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            cout<<a->arr[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
}
int fnf(struct node *a){
    int fn=0;
    //vartical
    for(int i=0;i<8;i++){
        if(a->arr[i][a->column]==1){
            fn++;
        }
    }
    //digonal1
    for(int i=a->row-1,j=a->column-1;i>=0&&j>=0;i--,j--){
        if(a->arr[i][j]==1){
            fn++;
        }
    }
    for(int i=a->row+1,j=a->column+1;i<=7&&j<=7;i++,j++){
        if(a->arr[i][j]==1){
            fn++;
        }
    }
    //diagonal2
    for(int i=a->row-1,j=a->column+1;i>=0&&j<=7;i--,j++){
        if(a->arr[i][j]==1){
            fn++;
        }
    }
    for(int i=a->row+1,j=a->column-1;i<=7&&j>=0;i++,j--){
        if(a->arr[i][j]==1){
            fn++;
        }
    }
    a->fn=fn+a->hn+a->gn+a->row;
    fn=a->fn;
    cout<<fn<<"\n";
    return fn;
}
void Queen8(struct node *a){
    struct node *last;
    last=(struct node *)malloc(sizeof(struct node));
    int t=1;
    while(a->row<8){
        for(int i=0;i<8;i++){
            struct node *b;
            b=(struct node *)malloc(sizeof(struct node));
            for(int j=0;j<8;j++){
                for(int k=0;k<8;k++){
                    b->arr[j][k]=a->arr[j][k];
                }
            }
            b->row=a->row+1;
            b->hn=8-a->row;
            b->column=i;
            b->arr[b->row][i]=1;
            if(t==1&&fnf(b)<=10){
                a->next=b;
                last=b;
                last->next=NULL;
                t=0;
            }else if(fnf(b)<=10){
                last->next=b;
                last=b;
                last->next=NULL;
            }
            //print(b);
        }
        if(a->next!=NULL)
            a=a->next;
        //print(a);
        if(a->row==7){
            print(a);
            return;
        }
        //cout<<"\n"<<a->row;
    }
}
int main(){
    struct node *a;
    a=(struct node *)malloc(sizeof(struct node));
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            a->arr[i][j]=0;
        }
    }
    a->row=-1;
    a->hn=8;
    a->next=NULL;
    Queen8(a);
    return 0;
}
