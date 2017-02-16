﻿/*
 * (c) Copyright Ascensio System SIA 2010-2017
 *
 * This program is a free software product. You can redistribute it and/or
 * modify it under the terms of the GNU Affero General Public License (AGPL)
 * version 3 as published by the Free Software Foundation. In accordance with
 * Section 7(a) of the GNU AGPL its Section 15 shall be amended to the effect
 * that Ascensio System SIA expressly excludes the warranty of non-infringement
 * of any third-party rights.
 *
 * This program is distributed WITHOUT ANY WARRANTY; without even the implied
 * warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR  PURPOSE. For
 * details, see the GNU AGPL at: http://www.gnu.org/licenses/agpl-3.0.html
 *
 * You can contact Ascensio System SIA at Lubanas st. 125a-25, Riga, Latvia,
 * EU, LV-1021.
 *
 * The  interactive user interfaces in modified source and object code versions
 * of the Program must display Appropriate Legal Notices, as required under
 * Section 5 of the GNU AGPL version 3.
 *
 * Pursuant to Section 7(b) of the License you must retain the original Product
 * logo when distributing the program. Pursuant to Section 7(e) we decline to
 * grant you any rights under trademark law for use of our trademarks.
 *
 * All the Product's GUI elements, including illustrations and icon sets, as
 * well as technical writing content are licensed under the terms of the
 * Creative Commons Attribution-ShareAlike 4.0 International. See the License
 * terms at http://creativecommons.org/licenses/by-sa/4.0/legalcode
 *
 */
#pragma once
#ifndef PPTX_LOGIC_EFFECTLST_INCLUDE_H_
#define PPTX_LOGIC_EFFECTLST_INCLUDE_H_

#include "./../WrapperWritingElement.h"
#include "Effects/Blur.h"
#include "Effects/Glow.h"
#include "Effects/OuterShdw.h"
#include "Effects/PrstShdw.h"
#include "Effects/InnerShdw.h"
#include "Effects/Reflection.h"
#include "Effects/SoftEdge.h"
#include "Effects/FillOverlay.h"

namespace PPTX
{
	namespace Logic
	{
		class EffectLst : public WrapperWritingElement
		{
		public:			
			WritingElement_AdditionConstructors(EffectLst)
			PPTX_LOGIC_BASE2(EffectLst)

            EffectLst& operator=(const EffectLst& oSrc);

			virtual OOX::EElementType getType () const
			{
				return OOX::et_a_effectLst;
			}
			virtual void fromXML(XmlUtils::CXmlLiteReader& oReader);

			void ReadAttributes(XmlUtils::CXmlLiteReader& oReader)
			{
				WritingElement_ReadAttributes_Start	( oReader )
				WritingElement_ReadAttributes_End	( oReader )
			}
			
			virtual void fromXML(XmlUtils::CXmlNode& node);

            virtual std::wstring toXML() const;

			virtual void toPPTY(NSBinPptxRW::CBinaryFileWriter* pWriter) const
			{
				pWriter->StartRecord(EFFECTPROPERTIES_TYPE_LIST);

				pWriter->WriteRecord2(0, blur);
				pWriter->WriteRecord2(1, fillOverlay);
				pWriter->WriteRecord2(2, glow);
				pWriter->WriteRecord2(3, innerShdw);
				pWriter->WriteRecord2(4, outerShdw);
				pWriter->WriteRecord2(5, prstShdw);
				pWriter->WriteRecord2(6, reflection);
				pWriter->WriteRecord2(7, softEdge);

				pWriter->EndRecord();
			}

		public:
			nullable<Blur>			blur;
			nullable<FillOverlay>	fillOverlay;
			nullable<Glow>			glow;
			nullable<InnerShdw>		innerShdw;
			nullable<OuterShdw>		outerShdw;
			nullable<PrstShdw>		prstShdw;
			nullable<Reflection>	reflection;
			nullable<SoftEdge>		softEdge;
		protected:
            virtual void FillParentPointersForChilds();

		};
	} // namespace Logic
} // namespace PPTX

#endif // PPTX_LOGIC_EFFECTLST_INCLUDE_H_
