#include "../header/Spread_Sheet.h"

//int arr[10] = {31, 32, 35, 33, 31, 34, 35, 36, 33, 32};

SpreadSheet::SpreadSheet()
    : board{nullptr},
      rowcnt(0),
      colcnt(0)
    {}

SpreadSheet::SpreadSheet(const SpreadSheet& rhv)
    :board{new Cell*[rhv.rowcnt]},
     rowcnt{rhv.rowcnt},
     colcnt{rhv.colcnt}
  {

    for(int i = 0; i < rowcnt; ++i){
        board[i] = new Cell[colcnt];
    }
  }

SpreadSheet::SpreadSheet(SpreadSheet&& rhv){
board = rhv.board;
	rowcnt = rhv.rowcnt;
    colcnt = rhv.colcnt;
	rhv.board = nullptr;
	rhv.rowcnt = 0;
    rhv.colcnt = 0;
}
   

SpreadSheet::SpreadSheet(size_t size)
    :board{new Cell*[size]}, 
     rowcnt{size},
     colcnt{size}
  {

      for(int i = 0; i < size; ++i){
          board[i] = new Cell[size];
    }
  } 

SpreadSheet::SpreadSheet(size_t row, size_t col)
    :board{new Cell*[row]},       
     rowcnt{row},
     colcnt{col}
  {

    for(int i = 0; i < row; ++i){
        board[i] = new Cell[col];
    }
  } 


SpreadSheet::~SpreadSheet(){
    clear();
}


const SpreadSheet& 
SpreadSheet::operator=(const SpreadSheet& rhv){
    if(this != &rhv){
        clear();
        board = new Cell*[rhv.rowcnt];       
        rowcnt = rhv.rowcnt;
        colcnt = rhv.colcnt;
        
        for (size_t i = 0; i < rhv.rowcnt; ++i) {    
            board[i] = new Cell[rhv.colcnt];
				for (size_t j = 0; j < rhv.colcnt; ++j) {
					board[i][j] = rhv.board[i][j];
			}
		}
	}
	return *this;
}

const SpreadSheet& SpreadSheet::operator=(SpreadSheet&& rhv){
    if(this != &rhv){
        clear();
        board = new Cell*[rhv.rowcnt];
        rowcnt = rhv.rowcnt;
        colcnt = rhv.colcnt;
            
        for (size_t i = 0; i < rhv.rowcnt; ++i) {
            board[i] = new Cell[rhv.colcnt];
                for (size_t j = 0; j < rhv.colcnt; ++j) {
                    board[i][j] = std::move(rhv.board[i][j]);
            }
        }
        
        rhv.clear();
		rhv.rowcnt = 0;
		rhv.colcnt = 0;  	
    	}
    
    return *this;
}

const SpreadSheet::Column& 
SpreadSheet::operator[](size_t pos){

    return Column(board[pos]);
}

const SpreadSheet::Column
SpreadSheet:: operator[](size_t pos) const{

    return Column(board[pos]);
}


void 
SpreadSheet::clear() noexcept{

    for(size_t i = 0 ; i < rowcnt; ++i){
        delete[] board[i];
     }

    delete[] board;
    board = nullptr;
  }


size_t 
SpreadSheet::row() const{

    return rowcnt;
}

size_t 
SpreadSheet::col() const{

    return colcnt;
}

void
SpreadSheet::mirrorH(){
    for(size_t i = 0; i < rowcnt; ++i ){
        for(size_t j = 0; j < colcnt / 2; ++j ){
            std::swap(board[i][j], board[i][colcnt - j - 1]);
        }
    }
}

void 
SpreadSheet::mirrorV(){
    for(size_t i = 0; i < rowcnt; ++i ){
        for(size_t j = 0; j < colcnt / 2; ++j ){
            std::swap(board[i][j], board[rowcnt - 1 - i][j]);
        }
    }
}

   
void 
SpreadSheet::mirrorD(){
    for(size_t i = 0; i < rowcnt; ++i ){
        for(size_t j = 0; j < colcnt / 2; ++j ){
            std::swap(board[i][j], board[j][i]);
        }
    }
}

    
void 
SpreadSheet::mirrorSD(){
    for(size_t i = 0; i < rowcnt; ++i ){
        for(size_t j = 0; j < colcnt / 2; ++j ){
            std::swap(board[i][j], board[rowcnt - 1 - j][colcnt - 1 - i]);
        }
    }
}

void
SpreadSheet::rotate(int cnt){
    if (cnt <= 0){
        return;
    }

    cnt %= 4;

    while(cnt--){
        Cell** tmp = new Cell*[colcnt];
            for(size_t i = 0; i < colcnt; ++i) {
                   tmp[i] = new Cell[rowcnt];
            for (int j = 0; j < rowcnt; ++j) {
                tmp[i][j] = board[rowcnt - 1 - j][i];
            }
        }

        size_t newRowCnt = colcnt;
        size_t newColCnt = rowcnt;

        clear();

        board = tmp;
        rowcnt = newRowCnt;
        colcnt = newColCnt;
    }
}

void
SpreadSheet::removeRow(size_t row){

    if (row >= rowcnt) {
        throw std::out_of_range("Row index out of range");
    }

    
    for(int i = row; i < rowcnt - 1; ++i){
        for(size_t j = 0; j < colcnt; ++j){
            board[i][j] = board[i + 1][j];
      }
    }
    delete[] board[rowcnt - 1];
    --rowcnt;
}


void SpreadSheet::removeRows(std::initializer_list<size_t> rows) {
    for (auto row : rows) {
       // if (row >= rowcnt) {
         //   throw std::out_of_range("Row index out of range");
       // }
        removeRow(row);
    }
}

void 
SpreadSheet::removeCol(size_t col) {
	if (col >= colcnt) {
		throw 0;
	}
	for (size_t i = 0; i < rowcnt; ++i) {
		for (size_t j = col; j < colcnt - 1; ++j) {
			board[i][j] = board[i][j + 1];		
    	}
	}
}

void 
SpreadSheet::removeCols(std::initializer_list<size_t> cols) {
	for (size_t col : cols) {
		removeCol(col);
	 }
}


void 
SpreadSheet::resizeRow(size_t r) {
	resize(r, colcnt);	
}

void 
SpreadSheet::resizeCol(size_t c) {
	resize(c, rowcnt);
}

void 
SpreadSheet::resize(size_t r, size_t c) {
	Cell** temp = new Cell*[r];
		for (size_t i = 0; i < r; ++i) {
			temp[i] = new Cell[c];
		}

	size_t min_rowcnt = std::min(r, rowcnt);
	size_t min_colcnt = std::min(c, colcnt);
	for (size_t i = 0; i < min_rowcnt; ++i) {
		for (size_t j = 0; j < min_colcnt; ++j) {
			temp[i][j] = board[i][j];
		}
	}
	clear();
	board = temp;
	rowcnt = r;
	colcnt = c;
	temp = nullptr;
}

SpreadSheet::SpreadSheet 
SpreadSheet::slice(std::initializer_list<size_t> rows, std::initializer_list<size_t> cols) {
	SpreadSheet temp(rows.size(), cols.size());
		size_t row_ind = 0;
		for (size_t i : rows) {
			size_t col_ind = 0;
			for (size_t j : cols) {
				if (i < rowcnt && j < colcnt) {
					temp.board[row_ind][col_ind] = board[i][j];
				}
				++col_ind;
			}
			++row_ind;
  		}
	return temp;
}


SpreadSheet::Column::Column(Cell* column) 
    : col{column} 
{}

Cell& SpreadSheet::Column::operator[](size_t pos){
    return col[pos];
}

const Cell& SpreadSheet::Column::operator[](size_t pos) const{
    return col[pos];
}


std::ostream& operator<<(std::ostream& out, const SpreadSheet& ob) {
    for (size_t i = 0; i < ob.row(); ++i) {
        for (size_t j = 0; j < ob.col(); ++j) {
            out << std::setw(10) << std::left<< ob[i][j] << '|';  
        }
      out << std::endl;
    }
    return out;
} //error: linker command failed with exit code 1 :((( p.s. i dont know what to do,but i gess just the code is wrong  


#endif

