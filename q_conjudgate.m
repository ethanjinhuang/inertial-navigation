function q0 = q_conjudgate(q)
% caculate the quaternion's conjudgate
% 计算四元数共轭
q0 = [q(1);-q(2:4)];