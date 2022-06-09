return true;
}
board[i][col] = '.';
}
}
return false;
}
vector<vector<string>> sols;
vector<vector<string>> solveNQueens(int n) {
vector<string> board(n, string(n, '.'));
if(solve(board,0,n)==false){
return sols;
}else{
sols.push_back(board);
return sols;
}
}
};