layout( binding=0 ) uniform sampler2D mapColour;

layout( location = 0 ) in vec2 vtx_texcoord;

layout( location = 0 ) out vec4 pxl_colour;

void main()
{
	pxl_colour = texture( mapColour, vtx_texcoord );
}
