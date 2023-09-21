// compile with: /D_UNICODE /DUNICODE /DWIN32 /D_WINDOWS /c

#include <cassert>
#include <simple/use_win32.hpp>
#include <simple/use_webview2.hpp>

static std::unique_ptr<WebViewAgent> agent_;

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_SIZE:
        if (agent_ != nullptr) {
            agent_->update_bounds();
        };
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
        break;
    }

    return 0;
}

int CALLBACK WinMain(_In_ HINSTANCE hInstance, _In_ HINSTANCE hPrevInstance, _In_ LPSTR     lpCmdLine, _In_ int       nCmdShow)
{
    auto hWnd = create_window({ .inst = hInstance, .icon = LoadIcon(hInstance, IDI_APPLICATION), .title = TEXT("HELLO WORLD"), .process = WndProc });
    assert(hWnd != 0);

    agent_ = std::make_unique<WebViewAgent>(hWnd);

    agent_->load_html(LR"(
<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8"> 
<title>菜鸟教程(runoob.com)</title> 
<script src="https://cdn.staticfile.org/jquery/1.10.2/jquery.min.js">
</script>
<script>
$(document).ready(function(){
  $("p").click(function(){
    $(this).hide();
  });
});
</script>
</head>
<body>
<p>如果你点我，我就会消失。</p>
<p>继续点我!</p>
<p>接着点我!</p>
</body>
</html>
            )");

    //agent_->load_url(L"http://localhost");


    // Main message loop:
    return exec_main_loop();
}

