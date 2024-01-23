struct BoundingBox{
    int min_row_idx;
    int min_col_idx;
    int max_row_idx;
    int max_col_idx;
};
void crop(int**& array, size_t& row_capacity, size_t& column_capacity, size_t& rows, size_t& columns, BoundingBox selected_area){
    //throwing appropriate exceptions
    if(BoundingBox.min_row_idx < 0 || BoundingBox.min_col_idx < 0 || BoundingBox.max_row_idx >= rows || BoundingBox.max_col_idx >= columns){
        throw std::out_of_range("Selected Area is either partially out of range or fully out of range");
    }
    //allocating new array
    int** newArray = new int* [BoundingBox.max_row_idx];
    for(int i = 0; i < BoundingBox.max_row_idx; i++){
        newArray[i] = new int [BoundingBox.max_col_idx];
    }
    //copying specificed area of old array into new array
    for(int row = BoundingBox.min_row_idx; row < BoundingBox.max_row_idx; row++){
        for(int col = BoundingBox.min_col_idx; col < BoundingBox.max_col_idx; col++){
            newArray[row][col] = array[row][col];
        }
    }
    //dellocating old array
    for(int i = 0; i < BoundingBox.max_row_idx; i++){
        delete[] array[i];
    }
    delete[] array;
    //updating values that need updating for the new array
    rows = BoundingBox.max_row_idx;
    columns = BoundingBox.max_col_idx;
    row_capacity = BoundingBox.max_row_idx;
    column_capacity = BoundingBox.max_col_idx;
    //setting the old array to equal the new array
    array = newArray;
    //dellocating the new array to avoid memory leaks
    for(int i = 0; i < BoundingBox.max_row_idx; i++){
        delete[] newArray[i];
    }
    delete[] newArray;
}