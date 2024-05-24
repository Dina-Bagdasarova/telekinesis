#include <iostream>
#include "../header/Spread_Sheet.h"

int main() {
    // Create a 3x3 spreadsheet
    SpreadSheet sheet(3, 3);

    // Fill the spreadsheet with some values
    for (size_t i = 0; i < sheet.row(); ++i) {
        for (size_t j = 0; j < sheet.col(); ++j) {
            int a = 10;
            sheet[i][j] = a;
            ++a;
        }
    }

    // Display the spreadsheet
    std::cout << "Original SpreadSheet:" << std::endl;
    //std::cout << sheet << std::endl;

    // Perform some operations
    sheet.mirrorH();
    std::cout << "After Horizontal Mirror:" << std::endl;
    //std::cout << sheet << std::endl;

    sheet.mirrorV();
    std::cout << "After Vertical Mirror:" << std::endl;
    //std::cout << sheet << std::endl;

    sheet.mirrorD();
    std::cout << "After Diagonal Mirror:" << std::endl;
   // std::cout << sheet << std::endl;

    sheet.rotate(1);
    std::cout << "After 1 Rotation:" << std::endl;
 //   std::cout << sheet << std::endl;

    return 0;
}




/*
#include <iostream>
#include "../header/cell.h"
#include "../header/Spread_Sheet.h"

int main() {
    // Create a few Cells
    Cell cell1(42);
    Cell cell2(3.14);
    Cell cell3('A');
    Cell cell4(true);
    Cell cell5("Hello");

    // Print Cells
    std::cout << "Cell1: " << cell1 << std::endl;
    std::cout << "Cell2: " << cell2 << std::endl;
    std::cout << "Cell3: " << cell3 << std::endl;
    std::cout << "Cell4: " << cell4 << std::endl;
    std::cout << "Cell5: " << cell5 << std::endl;

    // Create a SpreadSheet with 2 rows and 3 columns
    SpreadSheet sheet(2, 3);

    // Set values
    sheet[0][0] = cell1;
    sheet[0][1] = cell2;
    sheet[0][2] = cell3;
    sheet[1][0] = cell4;
    sheet[1][1] = cell5;
    sheet[1][2] = 100; // Using integer assignment

    // Print SpreadSheet
    std::cout << "SpreadSheet:" << std::endl;
//    std::cout << sheet;

    // Mirror horizontally and print
    sheet.mirrorH();
    std::cout << "After horizontal mirror:" << std::endl;
  //  std::cout << sheet;

    // Mirror vertically and print
    sheet.mirrorV();
    std::cout << "After vertical mirror:" << std::endl;
    //std::cout << sheet;

    // Rotate and print
    sheet.rotate(1);
    std::cout << "After one rotation:" << std::endl;
   // std::cout << sheet;

    return 0;
}*/

/*#include "../header/Spread_Sheet.h"

int main() {
    SpreadSheet sheet(3, 3);

    // Accessing and modifying cells
    sheet[0][0] = Cell("10");
    sheet[1][1] = Cell("20");
    sheet[2][2] = Cell("30");

    // Mirroring horizontally
    sheet.mirrorH();

    // Rotating sheet
    sheet.rotate(1);

    return 0;
}*/

