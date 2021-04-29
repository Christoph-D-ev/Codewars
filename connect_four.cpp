//checks the row wich was modified
//returns true if 4 consecutive trues exist in row

bool check_hor(bool board[8][6],int x,int y){
  int c=0;
  //calculating a window in a row takes more steps than checking all
  //dont bother
  for(int i=0;i<8;i++){
    if(board[i][y]){
      c++;
      if(c==4){
        return true;
       }
    }
    else{
      c=0;
    }
  }

    return false;
  
}
//checks the 3 spots below the modified one
//return true if all of those are true
bool check_vert(bool board[8][6],int x, int y){
  //only check down
  return y>=3&&board[x][y-1]&&board[x][y-2]&&board[x][y-3];
}

//checks the diagonal wich runs through the modified point
//wich ends in the "upper right corner"
//returns true if 4 consecutive trues exist
bool check_right_up(bool board[8][6],int x, int y){
  int start_x = x ;
  int start_y = y ;
  while(start_x>0&&start_y>0){
    start_x--;
    start_y--;
  }
  
  int c =0;
  while(start_x<7&&start_y<6){
    if(board[start_x][start_y]){
      c++;
      if(c==4){
        return true;
      }
    }
    else{
      c=0;
    }
    start_x++;
    start_y++;
  }
  return false;
}
//checks the diagonal wich runs through the modified point
//wich ends in the "ulower right corner"
//returns true if 4 consecutive trues exist
bool check_right_down(bool board[8][6],int x, int y){
  int start_x = x;
  int start_y = y;
  while(start_x>0&&start_y<5){
    start_x--;
    start_y++;
  }
  int c =0;
  while(start_x<=6&&start_y>=0){
    if(board[start_x][start_y]){
      c++;
      if(c==4){
        return true;
      }
    }else{
      c=0;
    }
    start_x++;
    start_y--;
  }
  return false;
}
//helper method
bool win_test(bool board[8][6],int x, int y){
    return check_hor(board, x,  y)||
    check_vert(board, x,  y)||
    check_right_up( board, x,  y)||
    check_right_down(board,x,  y);
}

//print for debug
void print_board(bool board_yellow[8][6],bool board_red[8][6]){
 std::cout<<"-------------"<<std::endl;
  for(int i=5;i>=0;i--){
    std::cout<<"|";
    for(int j=0;j<8;j++){
      if(board_yellow[j][i]){
        std::cout<<'y';
      }
      else{
        if(board_red[j][i]){
        std::cout<<'r';
      }
        else{
          
        std::cout<<'O';
      
        }
      }
      
    }
     std::cout<<"|"<<std::endl;
  }
    std::cout<<"-------------"<<std::endl;
}
std::string who_is_winner(std::vector<std::string> pieces_position_list)
{
  
  bool board_red[8][6]{};
  bool board_yellow[8][6]{};
  int height[8]={};
  
  
  //reverse vector to pop_back new moves
  std::reverse(pieces_position_list.begin(),pieces_position_list.end());
 
  int column;
  char colour;
  
  //loop through all moves
  while(!pieces_position_list.empty()){
     //print_board(board_yellow,board_red);
    
    //convert row to int
    switch(pieces_position_list.back()[0]){
        case 'A':column=0;break;
        case 'B':column=1;break;
        case 'C':column=2;break;
        case 'D':column=3;break;
        case 'E':column=4;break;
        case 'F':column=5;break;
        case 'G':column=6;break; 
    }
    colour = pieces_position_list.back().back();
    pieces_position_list.pop_back();
   
    if(colour=='w'){
      
      board_yellow[column][height[column]]=1;
      if(win_test(board_yellow,column,height[column])){
        
        
        return "Yellow";
      }
    }
    else{
      board_red[column][height[column]]=1;
      if(win_test(board_red,column,height[column])){
         
        return "Red";
      }
    }
    height[column]=height[column]+1;
    
  
    
  }
  //if nobody has won yet its a draw
  return "Draw";
}
