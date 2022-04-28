#pragma once
#include "Renderer/Renderer.h"
namespace Engine
{
	class ENGINE_API Texture
	{
	private:
		unsigned int m_RendererID1;
		unsigned int m_RendererID2;
		std::string m_FilePath;
		unsigned char* m_LocalBuffer1;
		unsigned char* m_LocalBuffer2;
		int m_Width, m_Height, m_BPP;
	public:
		Texture(const std::string& path1);
		Texture(const std::string& path1, const std::string& path2);
		~Texture();

		void Bind1() const;
		void Unbind1() const;
		void Bind2() const;
		void Unbind2() const;

		inline int GetWidth() const { return m_Width; }
		inline int GetHeight() const { return m_Height; }
	};
}