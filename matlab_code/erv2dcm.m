function dcm = erv2dcm(erv)
    nm2=erv'*erv;
    if nm2<1e-8
        a=1-nm2*(1/6-nm2/120);b=0.5-nm2*(1/24-nm2/720);
    else
        nm=sqrt(nm2);
        a=sin(nm)/nm;
        b=(1-cos(nm))/nm2;
    end
    
    VX=askew(erv);
    dcm=eye(3)+a*VX+b*VX^2;
end

