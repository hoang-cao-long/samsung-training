#include <iostream>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

struct Node{
	int value, x, y;

	Node(int value, int x, int y){
		this->value = value;
		this->x = x;
		this->y = y;
	}
};

int arr[101][101], T, N;
static int x, y, counting;
vector<Node> arr_around;

void get_around(){
	arr_around.clear();
	if(x == 0){
		if(y == 0){
			arr_around.push_back(Node(arr[x+1][y], x+1, y));
			arr_around.push_back(Node(arr[x][y+1], x, y+1));
			arr_around.push_back(Node(arr[x+1][y+1], x+1, y+1));
		} else if(y == N-1){
			arr_around.push_back(Node(arr[x][y-1], x, y-1));
			arr_around.push_back(Node(arr[x+1][y], x+1, y));
			arr_around.push_back(Node(arr[x+1][y-1], x+1, y-1));
		} else{
			arr_around.push_back(Node(arr[x][y-1], x, y-1));
			arr_around.push_back(Node(arr[x][y+1], x, y+1));
			arr_around.push_back(Node(arr[x+1][y], x+1, y));
			arr_around.push_back(Node(arr[x+1][y+1], x+1, y+1));
			arr_around.push_back(Node(arr[x+1][y-1], x+1, y-1));
		}
	} else{
		if(x == N-1){
			if(y == 0){
				arr_around.push_back(Node(arr[x-1][y], x-1, y));
				arr_around.push_back(Node(arr[x][y+1], x, y+1));
				arr_around.push_back(Node(arr[x-1][y+1], x-1, y+1));
			} else if(y == N-1){
				arr_around.push_back(Node(arr[x][y-1], x, y-1));
				arr_around.push_back(Node(arr[x-1][y], x-1, y));
				arr_around.push_back(Node(arr[x-1][y-1], x-1, y-1));
			} else{
				arr_around.push_back(Node(arr[x][y-1], x, y-1));
				arr_around.push_back(Node(arr[x][y+1], x, y+1));
				arr_around.push_back(Node(arr[x-1][y], x-1, y));
				arr_around.push_back(Node(arr[x-1][y+1], x-1, y+1));
				arr_around.push_back(Node(arr[x-1][y-1], x-1, y-1));
			}
		} else{
			if(y == 0){
				arr_around.push_back(Node(arr[x-1][y], x-1, y));
				arr_around.push_back(Node(arr[x+1][y], x+1, y));
				arr_around.push_back(Node(arr[x][y+1], x, y+1));
				arr_around.push_back(Node(arr[x-1][y+1], x-1, y+1));
				arr_around.push_back(Node(arr[x+1][y+1], x+1, y+1));
			} else if(y == N-1){
				arr_around.push_back(Node(arr[x-1][y], x-1, y));
				arr_around.push_back(Node(arr[x+1][y], x+1, y));
				arr_around.push_back(Node(arr[x][y-1], x, y-1));
				arr_around.push_back(Node(arr[x-1][y-1], x-1, y-1));
				arr_around.push_back(Node(arr[x+1][y-1], x+1, y-1));
			} else{
				arr_around.push_back(Node(arr[x][y-1], x, y-1));
				arr_around.push_back(Node(arr[x][y+1], x, y+1));
				arr_around.push_back(Node(arr[x+1][y], x+1, y));
				arr_around.push_back(Node(arr[x-1][y], x-1, y));

				arr_around.push_back(Node(arr[x+1][y+1], x+1, y+1));
				arr_around.push_back(Node(arr[x+1][y-1], x+1, y-1));
				arr_around.push_back(Node(arr[x-1][y+1], x-1, y+1));
				arr_around.push_back(Node(arr[x-1][y-1], x-1, y-1));
			}
		}
	}
}

int position_min_node(){
	int position = 0;
	for(int i = 0; i < arr_around.size(); i++){
		if(arr_around[position].value > arr_around[i].value){
			position = i;
		}
	}
	return position;
}

void find_min_second(){
	get_around();
	int current_value = arr[x][y];
	int position_min = position_min_node();

	while (current_value >= arr_around[position_min].value)
	{
		if(arr_around.size() == 1){
			break;
		}

		arr_around.erase(arr_around.begin() + position_min);
		position_min = position_min_node();
	}

	if(current_value < arr_around[position_min].value){
		x = arr_around[position_min].x;
		y = arr_around[position_min].y;
		counting++;
		find_min_second();
	}
}

int main() {
	freopen("input.txt","r",stdin);

	cin >> T;
	for(int i = 0; i < T; i++){
		cin >> N >> x >> y;
		counting = 0;

		for(int j = 0; j < N; j++){
			for(int k = 0; k < N; k++){
				cin >> arr[j][k];
			}
		}

		find_min_second();

		cout << "#" << (i+1) << " " << counting<< endl;
	}

	return 0;
}