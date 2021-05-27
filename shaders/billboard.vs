#version 400

layout (location = 0) in vec3 vPos;

uniform vec3 uCameraPos;
uniform float uSize;
uniform vec3 uOffset;
uniform vec4 uColor;
uniform mat4 uVP;

out vec4 color;
out vec2 uv;

void main()
{
   color = uColor;
   uv = vPos.xy;
   vec3 translate = uOffset-uSize/2.0f;
   mat4 translation = mat4(1.0,0.0,0.0,0.0,
						   0.0,1.0,0.0,0.0,
						   0.0,0.0,1.0,0.0,
						   translate,1.0);
   mat4 scale = mat4(uSize, 0.0, 0.0, 0.0, 
					 0.0, uSize, 0.0, 0.0,
					 0.0, 0.0, uSize, 0.0, 
					 0.0, 0.0, 0.0, 1.0);
   vec3 y = vec3(0.0, 1.0, 0.0);
   vec3 z = normalize(uCameraPos);
   vec3 x = cross(y,z);
   mat4 rotation = mat4(x, 0.0, 
						y, 0.0,
						z, 0.0, 
						0.0, 0.0, 0.0, 1.0);
   gl_Position = uVP  * rotation * translation * scale * vec4(vPos, 1.0); 
}
