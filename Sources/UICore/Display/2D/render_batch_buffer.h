/*
**  UICore
**  Copyright (c) 1997-2015 The UICore Team
**
**  This software is provided 'as-is', without any express or implied
**  warranty.  In no event will the authors be held liable for any damages
**  arising from the use of this software.
**
**  Permission is granted to anyone to use this software for any purpose,
**  including commercial applications, and to alter it and redistribute it
**  freely, subject to the following restrictions:
**
**  1. The origin of this software must not be misrepresented; you must not
**     claim that you wrote the original software. If you use this software
**     in a product, an acknowledgment in the product documentation would be
**     appreciated but is not required.
**  2. Altered source versions must be plainly marked as such, and must not be
**     misrepresented as being the original software.
**  3. This notice may not be removed or altered from any source distribution.
**
**  Note: Some of the libraries UICore may link to may have additional
**  requirements or restrictions.
**
**  File Author(s):
**
**    Magnus Norddahl
**    Mark Page
*/

#pragma once

#include "UICore/Display/Render/texture.h"
#include "UICore/Display/Render/graphic_context.h"
#include "UICore/Display/Render/texture_2d.h"
#include "UICore/Display/Render/staging_texture.h"
#include "UICore/Display/2D/render_batcher.h"

namespace uicore
{
	class RenderBatchBuffer
	{
	public:
		RenderBatchBuffer(const std::shared_ptr<GraphicContext> &gc);

		std::shared_ptr<VertexArrayBuffer> get_vertex_buffer(const std::shared_ptr<GraphicContext> &gc, int &out_index);
		std::shared_ptr<Texture2D> get_texture_rgba32f(const std::shared_ptr<GraphicContext> &gc);
		std::shared_ptr<Texture2D> get_texture_r8(const std::shared_ptr<GraphicContext> &gc);
		std::shared_ptr<StagingTexture> get_transfer_rgba32f(const std::shared_ptr<GraphicContext> &gc);

		std::shared_ptr<StagingTexture> get_transfer_r8(const std::shared_ptr<GraphicContext> &gc, int &out_index);
		static const int num_vertex_buffers = 4;
		enum { vertex_buffer_size = 1024 * 1024 };
		char buffer[vertex_buffer_size];

		static const int rgba32f_width = 512;	// *** If changing this, remember to modify the path shaders ***
		static const int rgba32f_height = 4;
		static const int r8_size = 1024;	// *** If changing this, remember to modify the path shaders ***
		static const int num_rgba32f_buffers = 2;
		static const int num_r8_buffers = 2;

	private:
		std::shared_ptr<VertexArrayBuffer> vertex_buffers[num_vertex_buffers];
		int current_vertex_buffer = 0;

		std::shared_ptr<Texture2D> textures_rgba32f[num_rgba32f_buffers];
		int current_rgba32f_texture = 0;

		std::shared_ptr<Texture2D> textures_r8[num_r8_buffers];
		int current_r8_texture = 0;

		std::shared_ptr<StagingTexture> transfers_rgba32f[num_rgba32f_buffers];
		int current_rgba32f_transfer = 0;
		std::shared_ptr<StagingTexture> transfers_r8[num_r8_buffers];
		int current_r8_transfer = 0;
	};
}
