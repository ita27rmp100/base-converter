// import the library
#include "header.h"
// impor the modules we need
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
// IDs for controls
#define ID_BUTTON 1
#define ID_EDITBOX 2
#define ID_COMBOBOX_FROM 201
#define ID_COMBOBOX_TO 202

// Window Procedure to handle events
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
        case WM_CREATE: {
            // Create UI elements
            CreateWindow("STATIC", "Enter number:", WS_VISIBLE | WS_CHILD,
                         10, 10, 100, 20, hwnd, NULL, NULL, NULL);

            CreateWindow("EDIT", "", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL,
                         120, 10, 185, 20, hwnd, (HMENU)ID_EDITBOX, NULL, NULL);

            CreateWindow("STATIC", "From base:", WS_VISIBLE | WS_CHILD,
                         10, 40, 100, 20, hwnd, NULL, NULL, NULL);

            HWND hwndComboBoxFrom = CreateWindow("COMBOBOX", NULL, WS_VISIBLE | WS_CHILD | CBS_DROPDOWNLIST,
                                                 120, 40, 60, 120, hwnd, (HMENU)ID_COMBOBOX_FROM, NULL, NULL);

            CreateWindow("STATIC", "To base:", WS_VISIBLE | WS_CHILD,
                         190, 40, 100, 20, hwnd, NULL, NULL, NULL);

            HWND hwndComboBoxTo = CreateWindow("COMBOBOX", NULL, WS_VISIBLE | WS_CHILD | CBS_DROPDOWNLIST,
                                               250, 40, 60, 120, hwnd, (HMENU)ID_COMBOBOX_TO, NULL, NULL);
            const char* bases[] = {"2", "8", "10", "16"};
            for (int i = 0; i < 4; i++) {
                SendMessage(hwndComboBoxFrom, CB_ADDSTRING, 0, (LPARAM)bases[i]);
                SendMessage(hwndComboBoxTo, CB_ADDSTRING, 0, (LPARAM)bases[i]);
            }
            CreateWindow("BUTTON", "Convert", WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
                         120, 70, 80, 40, hwnd, (HMENU)ID_BUTTON, NULL, NULL);
            break;
        }
        case WM_COMMAND: {
            if (LOWORD(wParam) == ID_BUTTON) { // If Convert button clicked
                char num[32];
                char fromBaseStr[10];
                char toBaseStr[10];
                char SWT[30] = "ConversionTitle"; // SWT => SecondWindowTitle
                char result[255];
                GetWindowText(GetDlgItem(hwnd, ID_EDITBOX), num, sizeof(num));
                int fromBaseIndex = SendMessage(GetDlgItem(hwnd, ID_COMBOBOX_FROM), CB_GETCURSEL, 0, 0);
                int toBaseIndex = SendMessage(GetDlgItem(hwnd, ID_COMBOBOX_TO), CB_GETCURSEL, 0, 0);

                if (fromBaseIndex != CB_ERR && toBaseIndex != CB_ERR && strlen(num) > 0) {
                    // Get selected bases
                    SendMessage(GetDlgItem(hwnd, ID_COMBOBOX_FROM), CB_GETLBTEXT, fromBaseIndex, (LPARAM)fromBaseStr);
                    SendMessage(GetDlgItem(hwnd, ID_COMBOBOX_TO), CB_GETLBTEXT, toBaseIndex, (LPARAM)toBaseStr);

                    int from = atoi(fromBaseStr);
                    int to = atoi(toBaseStr);
                    // conversion with condition
                    if(from!=to && (from==2 || from==10 || from==8 || from==16) && (to==2 || to==10 || to==8 || to==16)){
                    if (from == 16){
                        if (to==8 || to==2){
                            sprintf(result,"Result : %s in base 16 is equal to %i in base %i\n",num,hex_to_BinOrOct(strupr(num),to),to);
                        }
                        else if (to ==10){
                            sprintf(result,"Result : %s in base 16 is equal to %i in base %i\n",num,hex_to_dec(strupr(num)),to);
                        }
                    }
                    else{
                        int num_int = abs(atoi(num));
                        char signED[0];
                        if (atoi(num)<0){
                            sprintf(signED,"-\0");
                        }
                        //from oct or bin to other bases
                        if(from == 8 || from ==2){
                            if(to==10){
                                sprintf(result,"'%s' in base %i is equal to '%c%i' in base %i \n",num,from,signED,bin_or_oct_ToDec(num_int,from),to);
                            }
                            else if(from==8 && to==2 || from==2 && to==8){
                                sprintf(result,"'%s' in base %i is equal to '%c%i' in base %i \n",num,from,signED,bt_oct_bin(num_int,from,to),to);
                            }
                            else if(to == 16 ){
                                sprintf(result,"'%s' in base %i is equal to '%c%s' in base 16 \n",num,from,signED,BinOrOct_to_hex(num_int,from));
                            }
                        }       
                        // convert from base 10 to other bases
                        else if (from == 10){
                            if (to==8 || to==2){
                                sprintf(result,"'%s' in base 10 is equal to '%c%i' in base %i\n",num,signED,decTo_bin_or_oct(atoi(num),to),to);
                            }
                            else if(to==16){
                                sprintf(result,"'%s' in base 10 is equal to '%s' in base 16\n",num,signED,decimalTo_hex(num_int));
                            }
                        }
                    }
                    }
                    else if(from==to && (from==2 || from==10 || from==8 || from==16) && (to==2 || to==10 || to==8 || to==16)){
                        sprintf(result,"*** same base , still the same ***");
                    }
                    else{
                        sprintf(result,"ERROR , THE CONVERT FROM BETWEEN THE BASES YOU ENTERD IS UNAVAILABLE");
                    }           
                    MessageBox(hwnd, result, "Conversion Result", MB_OK | MB_ICONINFORMATION);
                } else {
                    MessageBox(hwnd, "Please enter a valid number and select bases.", "Input Error", MB_ICONERROR);
                }
            }
            break;
        }
        case WM_DESTROY: {
            PostQuitMessage(0);
            break;
        }
        default:
            return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
    return 0;
}
// Entry point of the application
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    // window title
    const char CLASS_NAME[] = "BaseConverter";
    WNDCLASS wc = {0};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;

    RegisterClass(&wc);

    HWND hwnd = CreateWindowEx(
        0,
        CLASS_NAME,
        "Bases Converter",
        WS_OVERLAPPEDWINDOW & ~(WS_THICKFRAME | WS_MAXIMIZEBOX), // Non-resizable
        CW_USEDEFAULT, CW_USEDEFAULT, 325, 150, // select the size of window
        NULL, NULL, hInstance, NULL
    );
    if (hwnd == NULL) {
        return 0;
    }
    ShowWindow(hwnd, nCmdShow);
    MSG msg = {0};
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return 0;
}