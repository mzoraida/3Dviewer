#ifdef GL_ES
// Set default precision to medium
precision mediump int;
precision mediump float;
#endif

// uniform sampler2D texture;
uniform mediump vec4 color;

//! [0]
void main()
{
    // Set color
    gl_FragColor = color;
}
//! [0]

