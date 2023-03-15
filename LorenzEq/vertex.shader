#version 330 core

layout(location = 0) in vec3 i_position;

out float fragDepth;

uniform mat4 worldMat, viewMat, projMat;

void main() 
{
	gl_Position = projMat * viewMat * worldMat * vec4(i_position, 1.0f);
	fragDepth = gl_Position.z / gl_Position.w;
	gl_PointSize = (1.0 - fragDepth) * 1000.0f;
} 
