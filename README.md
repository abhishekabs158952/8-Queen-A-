# 8-Queen-A-
# 1801005
# Abhishek kumar

variable :
i.)a : type struct node{
    	int arr[8][8];
 	    int row;
    	int column;
  	  int gn=1;
	    int fn; 
    	int hn;
    	struct node *next;
	};
discription :
1.)fn = gn + hn   ,fn deside which path to travese first
2.)hn = 8-level(level : depth of tree)  ,hn is hueiristic value of node
3.)gn = level(row) ,gn is path cost

main : 
1.)Queen8
	1.i)valid


discription :
1.)Queen8 :
	it also turns out to became BFS as fn=gn+hn and hn decrese by 1 each level and gn increse by 1 in each level
	1.i)valid :
		check whether the node is valid (no queen is at attacking position to other)
