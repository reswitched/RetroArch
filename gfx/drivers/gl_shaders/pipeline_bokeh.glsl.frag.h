#include "shaders_common.h"

static const char* stock_fragment_xmb_bokeh = GLSL(
   uniform float time;
   uniform vec2 OutputSize;

   void main(void)
   {
      float tim = time * 2.4;
      vec2 uv = -1.0 + 2.0*gl_FragCoord.xy / OutputSize.xy;
      uv.x *=  OutputSize.x / OutputSize.y;
      vec3 color = vec3(0.0);

      for( int i=0; i< 8; i++ )
      {
         float pha =      sin(float(i)*546.13+1.0)*0.5 + 0.5;
         float siz = pow( sin(float(i)*651.74+5.0)*0.5 + 0.5, 4.0 );
         float pox = sin(float(i)*321.55+4.1) * OutputSize.x / OutputSize.y;
         float rad = 0.1+0.5*siz+sin(pha+siz)/4.0;
         vec2  pos = vec2( pox+sin(time/15.+pha+siz), -1.0-rad + (2.0+2.0*rad)*mod(pha+0.3*(time/7.)*(0.2+0.8*siz),1.0));
         float dis = length( uv - pos );
         vec3  col = mix( vec3(0.194*sin(time/6.0)+0.3,0.2,0.3*pha), vec3(1.1*sin(time/9.0)+0.3,0.2*pha,0.4), 0.5+0.5*sin(float(i)));
         float f = length(uv-pos)/rad;
         f = sqrt(clamp(1.0+(sin((time)*siz)*0.5)*f,0.0,1.0));
         color += col.zyx *(1.0-smoothstep( rad*0.15, rad, dis ));
      }
      color *= sqrt(1.5-0.5*length(uv));
      gl_FragColor = vec4(color.r, color.g, color.b ,0.6);
   }

);
