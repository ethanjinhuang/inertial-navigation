function Euler= dcm2euler(dcm)
    if(abs(dcm(3,2))<=0.999999)
        Euler=[-atan2(dcm(1,2),dcm(2,2));asin(dcm(3,2));-atan2(dcm(3,1),dcm(3,3))];
    else
       Euler=[0;asin(dcm(3,2));atan2(dcm(1,3),dcm(1,1))]; 
    end
end

