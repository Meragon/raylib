#version 330

// Input vertex attributes (from vertex shader)
varying vec2 fragTexCoord;
varying vec4 fragColor;

// Input uniform values
uniform sampler2D texture0;

// NOTE: Add here your custom variables
const float smoothing = .1f;

void main()
{
    // Texel color fetching from texture sampler
    // NOTE: Calculate alpha using signed distance field (SDF)
    float distance = texture2D(texture0, fragTexCoord).a;
    float alpha = smoothstep(0.5f - smoothing, 0.5f + smoothing, distance);

    // Calculate final fragment color
    gl_FragColor = vec4(fragColor.rgb, fragColor.a*alpha);
}
