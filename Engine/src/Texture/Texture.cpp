#include "Texture.h"
#include "stb_image.h"
namespace Engine
{
	Texture::Texture(const std::string& path)
		: m_RendererID1(0), m_FilePath(path), m_LocalBuffer1(nullptr),
		m_Width(0), m_Height(0), m_BPP(0)
	{
		stbi_set_flip_vertically_on_load(1);
		m_LocalBuffer1 = stbi_load(path.c_str(), &m_Width, &m_Height, &m_BPP, 4);

		GLCall(glGenTextures(1, &m_RendererID1));
		GLCall(glBindTexture(GL_TEXTURE_2D, m_RendererID1));

		GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR));
		GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));
		GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE));
		GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE));

		GLCall(glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, m_Width, m_Height, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_LocalBuffer1));
		GLCall(glBindTexture(GL_TEXTURE_2D, 0));

		if (m_LocalBuffer1)
			stbi_image_free(m_LocalBuffer1);
	}
	Texture::Texture(const std::string& path1, const std::string& path2)
	: m_RendererID1(0), m_FilePath(path1), m_LocalBuffer1(nullptr), m_LocalBuffer2(nullptr),
		m_Width(0), m_Height(0), m_BPP(0)
	{
		stbi_set_flip_vertically_on_load(1);
		m_LocalBuffer1 = stbi_load(path1.c_str(), &m_Width, &m_Height, &m_BPP, 4);
		m_LocalBuffer2 = stbi_load(path2.c_str(), &m_Width, &m_Height, &m_BPP, 4);

		GLCall(glGenTextures(1, &m_RendererID1));
		GLCall(glBindTexture(GL_TEXTURE_2D, m_RendererID1));

		GLCall(glGenTextures(1, &m_RendererID2));
		GLCall(glBindTexture(GL_TEXTURE_2D, m_RendererID2));

		GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR));
		GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));
		GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE));
		GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE));

		GLCall(glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, m_Width, m_Height, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_LocalBuffer1));
		GLCall(glBindTexture(GL_TEXTURE_2D, 0));

		GLCall(glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, m_Width, m_Height, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_LocalBuffer2));
		GLCall(glBindTexture(GL_TEXTURE_2D, 0));

		if (m_LocalBuffer1)
			stbi_image_free(m_LocalBuffer1);
		if (m_LocalBuffer2)
			stbi_image_free(m_LocalBuffer2);
	}
	Texture::~Texture()
	{
		GLCall(glDeleteTextures(1, &m_RendererID1));
	}
	void Texture::Bind1() const
	{
		GLCall(glActiveTexture(GL_TEXTURE0));
		GLCall(glBindTexture(GL_TEXTURE_2D, m_RendererID1));
	}
	void Texture::Unbind1() const
	{
		GLCall(glBindTexture(GL_TEXTURE_2D, 0));
	}
	void Texture::Bind2() const
	{
		GLCall(glActiveTexture(GL_TEXTURE1));
		GLCall(glBindTexture(GL_TEXTURE_2D, m_RendererID2));
	}
	void Texture::Unbind2() const
	{
		GLCall(glBindTexture(GL_TEXTURE_2D, 1));
	}
}