function f() {
    var t = parseInt(prompt("", ""));

    while(t--)
    {
        var p,n=0,r,f=1;

        p = parseInt(prompt("", ""));

    if(p>=2048)
        {
            f = p/2048;
            p = p - f*2048;
        }

        while(p)
        {
            r = p%2;
            p = p/2;
            if(r==1)
                n++;
        }
        if(f>1)
            console.log(f+n+"\n");
        else
            console.log(n+"\n");
    }
}