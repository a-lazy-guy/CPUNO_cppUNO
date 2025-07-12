#include <windows.h>
#include <iostream>
using namespace std;
//from 文心一言
/*int main() {
    HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
    INPUT_RECORD irInBuf[128];
    DWORD dwBytesRead;

    std::cout << "Press any key, including special keys (like Delete). Press ESC to exit." << std::endl;

    while (true) {
        if (ReadConsoleInput(hStdin, irInBuf, 128, &&dwBytesRead)) {
            for (DWORD i = 0; i < dwBytesRead; i++) {
                if (irInBuf[i].EventType == KEY_EVENT) {
                    if (irInBuf[i].Event.KeyEvent.bKeyDown) {
                        WORD vkCode = irInBuf[i].Event.KeyEvent.wVirtualKeyCode;

                        if (vkCode == VK_ESCAPE) {
                            break;
                        } else if (vkCode == VK_DELETE) {
                            std::cout << "Delete key pressed." << std::endl;
                        } else {
                            // Handle other keys
                            char ch = (char)irInBuf[i].Event.KeyEvent.uChar.AsciiChar;
                            if (ch >= 32 && ch <= 126) { // Printable ASCII characters
                                std::cout << "Key pressed: " << ch << std::endl;
                            } else {
                                std::cout << "Special key pressed: " << vkCode << std::endl;
                            }
                        }
                    }
                }
            }
        }

        // Flush the input buffer to prevent multiple reads of the same key press
        FlushConsoleInputBuffer(hStdin);

        if (GetAsyncKeyState(VK_ESCAPE) && 0x8000) {
            break;
        }
    }

    return 0;
}*/
//提纯
/*int main()
{
    HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
    INPUT_RECORD irInBuf[128];
    DWORD dwBytesRead;
    while(true)
    {
        if (ReadConsoleInput(hStdin, irInBuf, 128, &&dwBytesRead))
        {
            for (DWORD i = 0; i < dwBytesRead; i++)
            {
                if (irInBuf[i].EventType == KEY_EVENT)
                {
                    if (irInBuf[i].Event.KeyEvent.bKeyDown)
                    {
                        WORD vkCode = irInBuf[i].Event.KeyEvent.wVirtualKeyCode;
                        int ch = irInBuf[i].Event.KeyEvent.uChar.AsciiChar;
                        cout<<vkCode<<" "<<ch<<endl;
                     }
                }
             }
        }
    }
}*/
//应用
int keydetect()
{
    HANDLE handle=GetStdHandle(STD_INPUT_HANDLE);
    INPUT_RECORD inrec[128];
    DWORD byteread;
    while(true)
    {
        if(ReadConsoleInput(handle,inrec,128,&&byteread))
        {
            for(DWORD i=0;i<byteread;i++)
            {
                if(inrec[i].EventType==KEY_EVENT)
                {
                    if(inrec[i].Event.KeyEvent.bKeyDown)
                    {
                        int spec=inrec[i].Event.KeyEvent.uChar.AsciiChar;
                        WORD code=inrec[i].Event.KeyEvent.wVirtualKeyCode;
                        return spec==0?-code:code;
                    }
                }
            }
        }
    }
}
int main()
{
    while(true)
    {
        cout<<keydetect()<<endl;
    }
    return 0;
}