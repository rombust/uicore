/*
**  ClanLib SDK
**  Copyright (c) 1997-2015 The ClanLib Team
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
**  Note: Some of the libraries ClanLib may link to may have additional
**  requirements or restrictions.
**
**  File Author(s):
**
**    Magnus Norddahl
**    Mark Page
*/

#pragma once

#include "UICore/Display/TargetProviders/vertex_array_buffer_provider.h"
#include "UICore/GL/opengl.h"
#include "UICore/Core/System/disposable_object.h"
#include "gl3_buffer_object_provider.h"

namespace clan
{
	class GL3GraphicContextProvider;

	class GL3VertexArrayBufferProvider : public VertexArrayBufferProvider
	{
	public:
		GL3VertexArrayBufferProvider();
		~GL3VertexArrayBufferProvider();
		void create(int size, BufferUsage usage) override;
		void create(void *data, int size, BufferUsage usage) override;

		GLuint get_handle() const { return buffer.get_handle(); }

		void upload_data(GraphicContext &gc, int offset, const void *data, int size) override { buffer.upload_data(gc, offset, data, size); }
		void copy_from(GraphicContext &gc, TransferBuffer &transfer_buffer, int dest_pos, int src_pos, int size) override { buffer.copy_from(gc, transfer_buffer, dest_pos, src_pos, size); }
		void copy_to(GraphicContext &gc, TransferBuffer &transfer_buffer, int dest_pos, int src_pos, int size) override { buffer.copy_to(gc, transfer_buffer, dest_pos, src_pos, size); }

	private:
		GL3BufferObjectProvider buffer;
	};
}
