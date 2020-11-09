function q = erv2q(erv)
% transform Equivalent rotation vector to quaternion
% 将等效旋转矢量转换为四元数
% 等效旋转矢量格式  [u1; u2; u3]
% 四元数格式       [q0; q1; q2; q3]
norm = sqrt(erv'*erv);  % 计算旋转矢量的模
if norm > 1.e-20
    f = sin(norm/2)/(norm/2);
else
    f = 1;
end
q = [cos(norm/2);f/2*erv];  % Q = q0 + qv = cos(phi/2) + usin(phi/2)