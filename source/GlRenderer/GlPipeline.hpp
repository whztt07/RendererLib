/**
*\file
*	Texture.h
*\author
*	Sylvain Doremus
*/
#ifndef ___VkRenderer_Pipeline_HPP___
#define ___VkRenderer_Pipeline_HPP___
#pragma once

#include "GlRendererPrerequisites.hpp"

#include <Renderer/Pipeline.hpp>
#include <Renderer/ColourBlendState.hpp>
#include <Renderer/DepthStencilState.hpp>
#include <Renderer/MultisampleState.hpp>
#include <Renderer/RasterisationState.hpp>
#include <Renderer/Scissor.hpp>
#include <Renderer/TessellationState.hpp>
#include <Renderer/Viewport.hpp>

#include <optional>

namespace gl_renderer
{
	/**
	*\brief
	*	Un pipeline de rendu.
	*/
	class Pipeline
		: public renderer::Pipeline
	{
	public:
		/**
		*\brief
		*	Constructeur.
		*\param[in] device
		*	Le LogicalDevice parent.
		*\param[in] layout
		*	Le layout du pipeline.
		*\param[in] program
		*	Le programme shader.
		*\param[in] vertexBuffers
		*	Les tampons de sommets utilisés.
		*\param[in] renderPass
		*	La passe de rendu.
		*\param[in] topology
		*	La topologie d'affichage des sommets affichés via ce pipeline.
		*/
		Pipeline( renderer::Device const & device
			, renderer::PipelineLayout const & layout
			, renderer::ShaderProgram const & program
			, renderer::VertexLayoutCRefArray const & vertexLayouts
			, renderer::RenderPass const & renderPass
			, renderer::PrimitiveTopology topology
			, renderer::RasterisationState const & rasterisationState
			, renderer::ColourBlendState const & colourBlendState );
		/**
		*\brief
		*	Crée le pipeline.
		*/
		renderer::Pipeline & finish()override;
		/**
		*\brief
		*	Définit le MultisampleState.
		*\param[in] state
		*	La nouvelle valeur.
		*/
		renderer::Pipeline & multisampleState( renderer::MultisampleState const & state )override;
		/**
		*\brief
		*	Définit le DepthStencilState.
		*\param[in] state
		*	La nouvelle valeur.
		*/
		renderer::Pipeline & depthStencilState( renderer::DepthStencilState const & state )override;
		/**
		*\brief
		*	Définit le TessellationState.
		*\param[in] state
		*	La nouvelle valeur.
		*/
		renderer::Pipeline & tessellationState( renderer::TessellationState const & state )override;
		/**
		*\brief
		*	Définit le Viewport.
		*\param[in] viewport
		*	La nouvelle valeur.
		*/
		renderer::Pipeline & viewport( renderer::Viewport const & viewport )override;
		/**
		*\brief
		*	Définit le Scissor.
		*\param[in] scissor
		*	La nouvelle valeur.
		*/
		renderer::Pipeline & scissor( renderer::Scissor const & scissor )override;
		/**
		*\return
		*	\p true si le MultisampleState est défini.
		*/
		inline bool hasMultisampleState()const
		{
			return m_msState.has_value();
		}
		/**
		*\return
		*	\p true si le DepthStencilState est défini.
		*/
		inline bool hasDepthStencilState()const
		{
			return m_dsState.has_value();
		}
		/**
		*\return
		*	\p true si le TessellationState est défini.
		*/
		inline bool hasTessellationState()const
		{
			return m_tsState.has_value();
		}
		/**
		*\return
		*	\p true si le Viewport est défini.
		*/
		inline bool hasViewport()const
		{
			return m_viewport.has_value();
		}
		/**
		*\return
		*	\p true si le Scissor est défini.
		*/
		inline bool hasScissor()const
		{
			return m_scissor.has_value();
		}
		/**
		*\return
		*	Le ColourBlendState.
		*/
		inline renderer::ColourBlendState const & getColourBlendState()const
		{
			return m_cbState;
		}
		/**
		*\return
		*	Le RasterisationState.
		*/
		inline renderer::RasterisationState const & getRasterisationState()const
		{
			return m_rsState;
		}
		/**
		*\return
		*	Le MultisampleState.
		*/
		inline renderer::MultisampleState const & getMultisampleState()const
		{
			return m_msState.value();
		}
		/**
		*\return
		*	Le DepthStencilState.
		*/
		inline renderer::DepthStencilState const & getDepthStencilState()const
		{
			return m_dsState.value();
		}
		/**
		*\return
		*	Le TessellationState.
		*/
		inline renderer::TessellationState const & getTessellationState()const
		{
			return m_tsState.value();
		}
		/**
		*\return
		*	Le Viewport.
		*/
		inline renderer::Viewport const & getViewport()const
		{
			return m_viewport.value();
		}
		/**
		*\return
		*	Le Scissor.
		*/
		inline renderer::Scissor const & getScissor()const
		{
			return m_scissor.value();
		}

	private:
		renderer::ColourBlendState m_cbState;
		renderer::RasterisationState m_rsState;
		std::optional< renderer::MultisampleState > m_msState;
		std::optional< renderer::DepthStencilState > m_dsState;
		std::optional< renderer::TessellationState > m_tsState;
		std::optional< renderer::Viewport > m_viewport;
		std::optional< renderer::Scissor > m_scissor;
	};
}

#endif