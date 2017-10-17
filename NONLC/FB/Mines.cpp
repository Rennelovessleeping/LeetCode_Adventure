/**************************************************************************
 * File Name : PutBombs.cpp
 *
 * Purpose :
 *
 * Creation Date : 23-02-2017
 *
 * Last Modified : Fri Sep 29 00:34:39 2017
 *
 * Created By :  
**************************************************************************/
// Given API rand() to generate a number between(0,1);
vector<vector<int>> putBombs(w, h, m){ // 1- bombs
	vector<vector<int>> res (h, vector<int>(w));
	vector<int> idx(m);
	int i;
	for(i=0; i<m; i++){ // put bombs in the first m sites in the flattened matrix
		res[i/w][i%w] = 1;
		idx[i] = i;
	}

	for(; i<h*w; i++){
		int j = rand()*INT_MAX % (i+1); // Generate random number between 0 and i with both boundaries included
		if(j<m) {
			swap(res[i/w][i%w], res[idx[j]/w][idx[j]%w]);
			idx[j] = i;
		}
	}
	return res;
}

