#if defined(__clang__)

#include "babble"

#include <OpenColorIO/OpenColorTransforms.h>
#include <OpenColorIO/OpenColorABI.h>
#include <OpenColorIO/OpenColorTypes.h>

#include <istream>

BBL_MODULE(ocio) {

  bbl::Class<OCIO_NAMESPACE::FormatMetadata>()
      .m(&OCIO_NAMESPACE::FormatMetadata::getElementName)
      .m(&OCIO_NAMESPACE::FormatMetadata::setElementName)
      .m(&OCIO_NAMESPACE::FormatMetadata::getElementValue)
      .m(&OCIO_NAMESPACE::FormatMetadata::setElementValue)
      .m(&OCIO_NAMESPACE::FormatMetadata::getNumAttributes)
      .m(&OCIO_NAMESPACE::FormatMetadata::getAttributeName)
      .m((char const *(OCIO_NAMESPACE::FormatMetadata::*)(int) const) &
         OCIO_NAMESPACE::FormatMetadata::getAttributeValue)
      .m((char const *(OCIO_NAMESPACE::FormatMetadata::*)(char const *) const) &
             OCIO_NAMESPACE::FormatMetadata::getAttributeValue,
         "getAttributeValue_const")
      .m(&OCIO_NAMESPACE::FormatMetadata::addAttribute)
      .m(&OCIO_NAMESPACE::FormatMetadata::getNumChildrenElements)
      .m((OCIO_NAMESPACE::FormatMetadata &
          (OCIO_NAMESPACE::FormatMetadata::*)(int)) &
         OCIO_NAMESPACE::FormatMetadata::getChildElement)
      .m((OCIO_NAMESPACE::FormatMetadata const &(
             OCIO_NAMESPACE::FormatMetadata::*)(int) const) &
             OCIO_NAMESPACE::FormatMetadata::getChildElement,
         "getChildElement_const")
      .m(&OCIO_NAMESPACE::FormatMetadata::addChildElement)
      .m(&OCIO_NAMESPACE::FormatMetadata::clear)
      .m(&OCIO_NAMESPACE::FormatMetadata::getName)
      .m(&OCIO_NAMESPACE::FormatMetadata::setName)
      .m(&OCIO_NAMESPACE::FormatMetadata::getID)
      .m(&OCIO_NAMESPACE::FormatMetadata::setID);

  bbl::Class<OCIO_NAMESPACE::AllocationTransform>()
      .m(&OCIO_NAMESPACE::AllocationTransform::Create)
      .m(&OCIO_NAMESPACE::AllocationTransform::createEditableCopy)
      .m(&OCIO_NAMESPACE::AllocationTransform::getDirection)
      .m(&OCIO_NAMESPACE::AllocationTransform::setDirection)
      .m(&OCIO_NAMESPACE::AllocationTransform::getTransformType)
      .m(&OCIO_NAMESPACE::AllocationTransform::validate)

      .m(&OCIO_NAMESPACE::AllocationTransform::getAllocation)
      .m(&OCIO_NAMESPACE::AllocationTransform::setAllocation)
      .m(&OCIO_NAMESPACE::AllocationTransform::getNumVars)
      .m(&OCIO_NAMESPACE::AllocationTransform::getVars)
      .m(&OCIO_NAMESPACE::AllocationTransform::setVars);

  bbl::Class<OCIO_NAMESPACE::AllocationTransformRcPtr>(
      "AllocationTransformRcPtr")
      .smartptr_to<OCIO_NAMESPACE::AllocationTransform>()
      .m(&OCIO_NAMESPACE::AllocationTransformRcPtr::get);
  bbl::Class<OCIO_NAMESPACE::ConstAllocationTransformRcPtr>(
      "ConstAllocationTransformRcPtr")
      .smartptr_to<OCIO_NAMESPACE::AllocationTransform const>()
      .m(&OCIO_NAMESPACE::ConstAllocationTransformRcPtr::get);

  bbl::Class<OCIO_NAMESPACE::BuiltinTransform>()
      .m(&OCIO_NAMESPACE::BuiltinTransform::Create)
      .m(&OCIO_NAMESPACE::BuiltinTransform::createEditableCopy)
      .m(&OCIO_NAMESPACE::BuiltinTransform::getDirection)
      .m(&OCIO_NAMESPACE::BuiltinTransform::setDirection)
      .m(&OCIO_NAMESPACE::BuiltinTransform::getTransformType)
      .m(&OCIO_NAMESPACE::BuiltinTransform::validate)

      .m(&OCIO_NAMESPACE::BuiltinTransform::getStyle)
      .m(&OCIO_NAMESPACE::BuiltinTransform::setStyle)
      .m(&OCIO_NAMESPACE::BuiltinTransform::getDescription);

  bbl::Class<OCIO_NAMESPACE::BuiltinTransformRcPtr>("BuiltinTransformRcPtr")
      .smartptr_to<OCIO_NAMESPACE::BuiltinTransform>()
      .m(&OCIO_NAMESPACE::BuiltinTransformRcPtr::get);
  bbl::Class<OCIO_NAMESPACE::ConstBuiltinTransformRcPtr>(
      "ConstBuiltinTransformRcPtr")
      .smartptr_to<OCIO_NAMESPACE::BuiltinTransform const>()
      .m(&OCIO_NAMESPACE::ConstBuiltinTransformRcPtr::get);

  bbl::Enum<OCIO_NAMESPACE::CDLStyle>().prefix("");

  bbl::Class<OCIO_NAMESPACE::CDLTransform>()
      .m(&OCIO_NAMESPACE::CDLTransform::Create)
      .m(&OCIO_NAMESPACE::CDLTransform::createEditableCopy)
      .m(&OCIO_NAMESPACE::CDLTransform::getDirection)
      .m(&OCIO_NAMESPACE::CDLTransform::setDirection)
      .m(&OCIO_NAMESPACE::CDLTransform::getTransformType)
      .m(&OCIO_NAMESPACE::CDLTransform::validate)

      .m(&OCIO_NAMESPACE::CDLTransform::CreateFromFile)
      .m(&OCIO_NAMESPACE::CDLTransform::CreateGroupFromFile)
      .m((OCIO_NAMESPACE::FormatMetadata &
          (OCIO_NAMESPACE::CDLTransform::*)()) &
         OCIO_NAMESPACE::CDLTransform::getFormatMetadata)
      .m((OCIO_NAMESPACE::FormatMetadata const &(
             OCIO_NAMESPACE::CDLTransform::*)() const) &
             OCIO_NAMESPACE::CDLTransform::getFormatMetadata,
         "getFormatMetadata_const")
      .m(&OCIO_NAMESPACE::CDLTransform::equals)
      .m(&OCIO_NAMESPACE::CDLTransform::getStyle)
      .m(&OCIO_NAMESPACE::CDLTransform::setStyle)
      .m(&OCIO_NAMESPACE::CDLTransform::getSlope)
      .m(&OCIO_NAMESPACE::CDLTransform::setSlope)
      .m(&OCIO_NAMESPACE::CDLTransform::getOffset)
      .m(&OCIO_NAMESPACE::CDLTransform::setOffset)
      .m(&OCIO_NAMESPACE::CDLTransform::getPower)
      .m(&OCIO_NAMESPACE::CDLTransform::setPower)
      .m(&OCIO_NAMESPACE::CDLTransform::getSOP)
      .m(&OCIO_NAMESPACE::CDLTransform::setSOP)
      .m(&OCIO_NAMESPACE::CDLTransform::getSat)
      .m(&OCIO_NAMESPACE::CDLTransform::setSat)
      .m(&OCIO_NAMESPACE::CDLTransform::getSatLumaCoefs)
      .m(&OCIO_NAMESPACE::CDLTransform::getFirstSOPDescription)
      .m(&OCIO_NAMESPACE::CDLTransform::setFirstSOPDescription);

  bbl::Class<OCIO_NAMESPACE::CDLTransformRcPtr>("CDLTransformRcPtr")
      .smartptr_to<OCIO_NAMESPACE::CDLTransform>()
      .m(&OCIO_NAMESPACE::CDLTransformRcPtr::get);
  bbl::Class<OCIO_NAMESPACE::ConstCDLTransformRcPtr>("ConstCDLTransformRcPtr")
      .smartptr_to<OCIO_NAMESPACE::CDLTransform const>()
      .m(&OCIO_NAMESPACE::ConstCDLTransformRcPtr::get);

  bbl::Class<OCIO_NAMESPACE::ColorSpaceTransform>()
      .m(&OCIO_NAMESPACE::ColorSpaceTransform::Create)
      .m(&OCIO_NAMESPACE::ColorSpaceTransform::createEditableCopy)
      .m(&OCIO_NAMESPACE::ColorSpaceTransform::getDirection)
      .m(&OCIO_NAMESPACE::ColorSpaceTransform::setDirection)
      .m(&OCIO_NAMESPACE::ColorSpaceTransform::getTransformType)
      .m(&OCIO_NAMESPACE::ColorSpaceTransform::validate)

      .m(&OCIO_NAMESPACE::ColorSpaceTransform::getSrc)
      .m(&OCIO_NAMESPACE::ColorSpaceTransform::setSrc)
      .m(&OCIO_NAMESPACE::ColorSpaceTransform::getDst)
      .m(&OCIO_NAMESPACE::ColorSpaceTransform::setDst)
      .m(&OCIO_NAMESPACE::ColorSpaceTransform::getDataBypass)
      .m(&OCIO_NAMESPACE::ColorSpaceTransform::setDataBypass);

  bbl::Class<OCIO_NAMESPACE::ColorSpaceTransformRcPtr>(
      "ColorSpaceTransformRcPtr")
      .smartptr_to<OCIO_NAMESPACE::ColorSpaceTransform>()
      .m(&OCIO_NAMESPACE::ColorSpaceTransformRcPtr::get);
  bbl::Class<OCIO_NAMESPACE::ConstColorSpaceTransformRcPtr>(
      "ConstColorSpaceTransformRcPtr")
      .smartptr_to<OCIO_NAMESPACE::ColorSpaceTransform const>()
      .m(&OCIO_NAMESPACE::ConstColorSpaceTransformRcPtr::get);

  bbl::Class<OCIO_NAMESPACE::DisplayViewTransform>()
      .m(&OCIO_NAMESPACE::DisplayViewTransform::Create)
      .m(&OCIO_NAMESPACE::DisplayViewTransform::createEditableCopy)
      .m(&OCIO_NAMESPACE::DisplayViewTransform::getDirection)
      .m(&OCIO_NAMESPACE::DisplayViewTransform::setDirection)
      .m(&OCIO_NAMESPACE::DisplayViewTransform::getTransformType)
      .m(&OCIO_NAMESPACE::DisplayViewTransform::validate)

      .m(&OCIO_NAMESPACE::DisplayViewTransform::getSrc)
      .m(&OCIO_NAMESPACE::DisplayViewTransform::setSrc)
      .m(&OCIO_NAMESPACE::DisplayViewTransform::getDisplay)
      .m(&OCIO_NAMESPACE::DisplayViewTransform::setDisplay)
      .m(&OCIO_NAMESPACE::DisplayViewTransform::getView)
      .m(&OCIO_NAMESPACE::DisplayViewTransform::setView)
      .m(&OCIO_NAMESPACE::DisplayViewTransform::getLooksBypass)
      .m(&OCIO_NAMESPACE::DisplayViewTransform::setLooksBypass)
      .m(&OCIO_NAMESPACE::DisplayViewTransform::getDataBypass)
      .m(&OCIO_NAMESPACE::DisplayViewTransform::setDataBypass);

  bbl::Class<OCIO_NAMESPACE::DisplayViewTransformRcPtr>(
      "DisplayViewTransformRcPtr")
      .smartptr_to<OCIO_NAMESPACE::DisplayViewTransform>()
      .m(&OCIO_NAMESPACE::DisplayViewTransformRcPtr::get);
  bbl::Class<OCIO_NAMESPACE::ConstDisplayViewTransformRcPtr>(
      "ConstDisplayViewTransformRcPtr")
      .smartptr_to<OCIO_NAMESPACE::DisplayViewTransform const>()
      .m(&OCIO_NAMESPACE::ConstDisplayViewTransformRcPtr::get);

  bbl::Class<OCIO_NAMESPACE::DynamicProperty>().m(
      &OCIO_NAMESPACE::DynamicProperty::getType);

  bbl::Class<OCIO_NAMESPACE::DynamicPropertyRcPtr>("DynamicPropertyRcPtr")
      .smartptr_to<OCIO_NAMESPACE::DynamicProperty>()
      .m(&OCIO_NAMESPACE::DynamicPropertyRcPtr::get);
  bbl::Class<OCIO_NAMESPACE::ConstDynamicPropertyRcPtr>(
      "ConstDynamicPropertyRcPtr")
      .smartptr_to<OCIO_NAMESPACE::DynamicProperty const>()
      .m(&OCIO_NAMESPACE::ConstDynamicPropertyRcPtr::get);

  bbl::Class<OCIO_NAMESPACE::DynamicPropertyDouble>()
      .m(&OCIO_NAMESPACE::DynamicPropertyDouble::getValue)
      .m(&OCIO_NAMESPACE::DynamicPropertyDouble::setValue);

  bbl::Class<OCIO_NAMESPACE::DynamicPropertyDoubleRcPtr>(
      "DynamicPropertyDoubleRcPtr")
      .smartptr_to<OCIO_NAMESPACE::DynamicPropertyDouble>()
      .m(&OCIO_NAMESPACE::DynamicPropertyDoubleRcPtr::get);
  bbl::Class<OCIO_NAMESPACE::ConstDynamicPropertyDoubleRcPtr>(
      "ConstDynamicPropertyDoubleRcPtr")
      .smartptr_to<OCIO_NAMESPACE::DynamicPropertyDouble const>()
      .m(&OCIO_NAMESPACE::ConstDynamicPropertyDoubleRcPtr::get);

  bbl::Class<OCIO_NAMESPACE::DynamicPropertyGradingPrimary>()
      .m(&OCIO_NAMESPACE::DynamicPropertyGradingPrimary::getValue)
      .m(&OCIO_NAMESPACE::DynamicPropertyGradingPrimary::setValue);

  bbl::Class<OCIO_NAMESPACE::DynamicPropertyGradingPrimaryRcPtr>(
      "DynamicPropertyGradingPrimaryRcPtr")
      .smartptr_to<OCIO_NAMESPACE::DynamicPropertyGradingPrimary>()
      .m(&OCIO_NAMESPACE::DynamicPropertyGradingPrimaryRcPtr::get);
  bbl::Class<OCIO_NAMESPACE::ConstDynamicPropertyGradingPrimaryRcPtr>(
      "ConstDynamicPropertyGradingPrimaryRcPtr")
      .smartptr_to<OCIO_NAMESPACE::DynamicPropertyGradingPrimary const>()
      .m(&OCIO_NAMESPACE::ConstDynamicPropertyGradingPrimaryRcPtr::get);

  bbl::Class<OCIO_NAMESPACE::DynamicPropertyGradingRGBCurve>()
      .m(&OCIO_NAMESPACE::DynamicPropertyGradingRGBCurve::getValue)
      .m(&OCIO_NAMESPACE::DynamicPropertyGradingRGBCurve::setValue);

  bbl::Class<OCIO_NAMESPACE::DynamicPropertyGradingRGBCurveRcPtr>(
      "DynamicPropertyGradingRGBCurveRcPtr")
      .smartptr_to<OCIO_NAMESPACE::DynamicPropertyGradingRGBCurve>()
      .m(&OCIO_NAMESPACE::DynamicPropertyGradingRGBCurveRcPtr::get);
  bbl::Class<OCIO_NAMESPACE::ConstDynamicPropertyGradingRGBCurveRcPtr>(
      "ConstDynamicPropertyGradingRGBCurveRcPtr")
      .smartptr_to<OCIO_NAMESPACE::DynamicPropertyGradingRGBCurve const>()
      .m(&OCIO_NAMESPACE::ConstDynamicPropertyGradingRGBCurveRcPtr::get);

  bbl::Class<OCIO_NAMESPACE::DynamicPropertyGradingTone>()
      .m(&OCIO_NAMESPACE::DynamicPropertyGradingTone::getValue)
      .m(&OCIO_NAMESPACE::DynamicPropertyGradingTone::setValue);

  bbl::Class<OCIO_NAMESPACE::DynamicPropertyGradingToneRcPtr>(
      "DynamicPropertyGradingToneRcPtr")
      .smartptr_to<OCIO_NAMESPACE::DynamicPropertyGradingTone>()
      .m(&OCIO_NAMESPACE::DynamicPropertyGradingToneRcPtr::get);
  bbl::Class<OCIO_NAMESPACE::ConstDynamicPropertyGradingToneRcPtr>(
      "ConstDynamicPropertyGradingToneRcPtr")
      .smartptr_to<OCIO_NAMESPACE::DynamicPropertyGradingTone const>()
      .m(&OCIO_NAMESPACE::ConstDynamicPropertyGradingToneRcPtr::get);

  bbl::fn(&OCIO_NAMESPACE::DynamicPropertyValue::AsDouble);
  bbl::fn(&OCIO_NAMESPACE::DynamicPropertyValue::AsGradingPrimary);
  bbl::fn(&OCIO_NAMESPACE::DynamicPropertyValue::AsGradingRGBCurve);
  bbl::fn(&OCIO_NAMESPACE::DynamicPropertyValue::AsGradingTone);

  bbl::Enum<OCIO_NAMESPACE::DynamicPropertyType>().prefix("");

  bbl::Class<OCIO_NAMESPACE::ExponentTransform>()
      .m(&OCIO_NAMESPACE::ExponentTransform::Create)
      .m(&OCIO_NAMESPACE::ExponentTransform::createEditableCopy)
      .m(&OCIO_NAMESPACE::ExponentTransform::getDirection)
      .m(&OCIO_NAMESPACE::ExponentTransform::setDirection)
      .m(&OCIO_NAMESPACE::ExponentTransform::getTransformType)
      .m(&OCIO_NAMESPACE::ExponentTransform::validate)
      .m(&OCIO_NAMESPACE::ExponentTransform::equals)
      .m(&OCIO_NAMESPACE::ExponentTransform::getValue)
      .m(&OCIO_NAMESPACE::ExponentTransform::setValue)
      .m(&OCIO_NAMESPACE::ExponentTransform::getNegativeStyle)
      .m(&OCIO_NAMESPACE::ExponentTransform::setNegativeStyle);

  bbl::Class<OCIO_NAMESPACE::ExponentTransformRcPtr>("ExponentTransformRcPtr")
      .smartptr_to<OCIO_NAMESPACE::ExponentTransform>()
      .m(&OCIO_NAMESPACE::ExponentTransformRcPtr::get);
  bbl::Class<OCIO_NAMESPACE::ConstExponentTransformRcPtr>(
      "ConstExponentTransformRcPtr")
      .smartptr_to<OCIO_NAMESPACE::ExponentTransform const>()
      .m(&OCIO_NAMESPACE::ConstExponentTransformRcPtr::get);

  bbl::Class<OCIO_NAMESPACE::ExponentWithLinearTransform>()
      .m(&OCIO_NAMESPACE::ExponentWithLinearTransform::Create)
      .m(&OCIO_NAMESPACE::ExponentWithLinearTransform::createEditableCopy)
      .m(&OCIO_NAMESPACE::ExponentWithLinearTransform::getDirection)
      .m(&OCIO_NAMESPACE::ExponentWithLinearTransform::setDirection)
      .m(&OCIO_NAMESPACE::ExponentWithLinearTransform::getTransformType)
      .m(&OCIO_NAMESPACE::ExponentWithLinearTransform::validate)
      .m(&OCIO_NAMESPACE::ExponentWithLinearTransform::equals)
      .m(&OCIO_NAMESPACE::ExponentWithLinearTransform::getNegativeStyle)
      .m(&OCIO_NAMESPACE::ExponentWithLinearTransform::setNegativeStyle)
      .m(&OCIO_NAMESPACE::ExponentWithLinearTransform::getGamma)
      .m(&OCIO_NAMESPACE::ExponentWithLinearTransform::setGamma)
      .m(&OCIO_NAMESPACE::ExponentWithLinearTransform::getOffset)
      .m(&OCIO_NAMESPACE::ExponentWithLinearTransform::setOffset)
      ;

  bbl::Class<OCIO_NAMESPACE::ExponentWithLinearTransformRcPtr>(
      "ExponentWithLinearTransformRcPtr")
      .smartptr_to<OCIO_NAMESPACE::ExponentWithLinearTransform>()
      .m(&OCIO_NAMESPACE::ExponentWithLinearTransformRcPtr::get);
  bbl::Class<OCIO_NAMESPACE::ConstExponentWithLinearTransformRcPtr>(
      "ConstExponentWithLinearTransformRcPtr")
      .smartptr_to<OCIO_NAMESPACE::ExponentWithLinearTransform const>()
      .m(&OCIO_NAMESPACE::ConstExponentWithLinearTransformRcPtr::get);

  bbl::Class<OCIO_NAMESPACE::ExposureContrastTransform>()
      .m(&OCIO_NAMESPACE::ExposureContrastTransform::Create)
      .m(&OCIO_NAMESPACE::ExposureContrastTransform::createEditableCopy)
      .m(&OCIO_NAMESPACE::ExposureContrastTransform::getDirection)
      .m(&OCIO_NAMESPACE::ExposureContrastTransform::setDirection)
      .m(&OCIO_NAMESPACE::ExposureContrastTransform::getTransformType)
      .m(&OCIO_NAMESPACE::ExposureContrastTransform::validate)
      .m(&OCIO_NAMESPACE::ExposureContrastTransform::equals)
      .m(&OCIO_NAMESPACE::ExposureContrastTransform::getStyle)
      .m(&OCIO_NAMESPACE::ExposureContrastTransform::setStyle)
      .m(&OCIO_NAMESPACE::ExposureContrastTransform::getExposure)
      .m(&OCIO_NAMESPACE::ExposureContrastTransform::setExposure)
      .m(&OCIO_NAMESPACE::ExposureContrastTransform::isExposureDynamic)
      .m(&OCIO_NAMESPACE::ExposureContrastTransform::makeExposureDynamic)
      .m(&OCIO_NAMESPACE::ExposureContrastTransform::makeExposureNonDynamic)
      .m(&OCIO_NAMESPACE::ExposureContrastTransform::getContrast)
      .m(&OCIO_NAMESPACE::ExposureContrastTransform::setContrast)
      .m(&OCIO_NAMESPACE::ExposureContrastTransform::makeContrastDynamic)
      .m(&OCIO_NAMESPACE::ExposureContrastTransform::makeContrastNonDynamic)
      .m(&OCIO_NAMESPACE::ExposureContrastTransform::isContrastDynamic)
      .m(&OCIO_NAMESPACE::ExposureContrastTransform::getGamma)
      .m(&OCIO_NAMESPACE::ExposureContrastTransform::setGamma)
      .m(&OCIO_NAMESPACE::ExposureContrastTransform::isGammaDynamic)
      .m(&OCIO_NAMESPACE::ExposureContrastTransform::makeGammaDynamic)
      .m(&OCIO_NAMESPACE::ExposureContrastTransform::makeGammaNonDynamic)
      .m(&OCIO_NAMESPACE::ExposureContrastTransform::getPivot)
      .m(&OCIO_NAMESPACE::ExposureContrastTransform::setPivot)
      .m(&OCIO_NAMESPACE::ExposureContrastTransform::getLogExposureStep)
      .m(&OCIO_NAMESPACE::ExposureContrastTransform::setLogExposureStep)
      .m(&OCIO_NAMESPACE::ExposureContrastTransform::getLogMidGray);

  bbl::Class<OCIO_NAMESPACE::ExposureContrastTransformRcPtr>(
      "ExposureContrastTransformRcPtr")
      .smartptr_to<OCIO_NAMESPACE::ExposureContrastTransform>()
      .m(&OCIO_NAMESPACE::ExposureContrastTransformRcPtr::get);
  bbl::Class<OCIO_NAMESPACE::ConstExposureContrastTransformRcPtr>(
      "ConstExposureContrastTransformRcPtr")
      .smartptr_to<OCIO_NAMESPACE::ExposureContrastTransform const>()
      .m(&OCIO_NAMESPACE::ConstExposureContrastTransformRcPtr::get);

  bbl::Class<OCIO_NAMESPACE::FileTransform>()
      .m(&OCIO_NAMESPACE::FileTransform::Create)
      .m(&OCIO_NAMESPACE::FileTransform::createEditableCopy)
      .m(&OCIO_NAMESPACE::FileTransform::getDirection)
      .m(&OCIO_NAMESPACE::FileTransform::setDirection)
      .m(&OCIO_NAMESPACE::FileTransform::getTransformType)
      .m(&OCIO_NAMESPACE::FileTransform::validate)
      .m(&OCIO_NAMESPACE::FileTransform::getSrc)
      .m(&OCIO_NAMESPACE::FileTransform::setSrc)
      .m(&OCIO_NAMESPACE::FileTransform::getCCCId)
      .m(&OCIO_NAMESPACE::FileTransform::setCCCId)
      .m(&OCIO_NAMESPACE::FileTransform::getCDLStyle)
      .m(&OCIO_NAMESPACE::FileTransform::setCDLStyle)
      .m(&OCIO_NAMESPACE::FileTransform::getInterpolation)
      .m(&OCIO_NAMESPACE::FileTransform::setInterpolation)
      .m(&OCIO_NAMESPACE::FileTransform::GetNumFormats)
      .m(&OCIO_NAMESPACE::FileTransform::GetFormatNameByIndex)
      .m(&OCIO_NAMESPACE::FileTransform::GetFormatExtensionByIndex);

  bbl::Class<OCIO_NAMESPACE::FileTransformRcPtr>("FileTransformRcPtr")
      .smartptr_to<OCIO_NAMESPACE::FileTransform>()
      .m(&OCIO_NAMESPACE::FileTransformRcPtr::get);
  bbl::Class<OCIO_NAMESPACE::ConstFileTransformRcPtr>("ConstFileTransformRcPtr")
      .smartptr_to<OCIO_NAMESPACE::FileTransform const>()
      .m(&OCIO_NAMESPACE::ConstFileTransformRcPtr::get);

  bbl::Enum<OCIO_NAMESPACE::FixedFunctionStyle>().prefix("");

  bbl::Class<OCIO_NAMESPACE::FixedFunctionTransform>()
      .m((OCIO_NAMESPACE::FixedFunctionTransformRcPtr(*)(
             OCIO_NAMESPACE::FixedFunctionStyle)) &
         OCIO_NAMESPACE::FixedFunctionTransform::Create)
      .m((OCIO_NAMESPACE::FixedFunctionTransformRcPtr(*)(
             OCIO_NAMESPACE::FixedFunctionStyle, double const *, size_t)) &
             OCIO_NAMESPACE::FixedFunctionTransform::Create,
         "Create_with_params")
      .m((OCIO_NAMESPACE::FormatMetadata &
          (OCIO_NAMESPACE::FixedFunctionTransform::*)()) &
         OCIO_NAMESPACE::FixedFunctionTransform::getFormatMetadata)
      .m((OCIO_NAMESPACE::FormatMetadata const &(
             OCIO_NAMESPACE::FixedFunctionTransform::*)() const) &
             OCIO_NAMESPACE::FixedFunctionTransform::getFormatMetadata,
         "getFormatMetadata_const")
      .m(&OCIO_NAMESPACE::FixedFunctionTransform::equals)
      .m(&OCIO_NAMESPACE::FixedFunctionTransform::createEditableCopy)
      .m(&OCIO_NAMESPACE::FixedFunctionTransform::getDirection)
      .m(&OCIO_NAMESPACE::FixedFunctionTransform::setDirection)
      .m(&OCIO_NAMESPACE::FixedFunctionTransform::getTransformType)
      .m(&OCIO_NAMESPACE::FixedFunctionTransform::validate)
      .m(&OCIO_NAMESPACE::FixedFunctionTransform::getStyle)
      .m(&OCIO_NAMESPACE::FixedFunctionTransform::setStyle)
      .m(&OCIO_NAMESPACE::FixedFunctionTransform::getNumParams)
      .m(&OCIO_NAMESPACE::FixedFunctionTransform::getParams)
      .m(&OCIO_NAMESPACE::FixedFunctionTransform::setParams);

  bbl::Class<OCIO_NAMESPACE::FixedFunctionTransformRcPtr>(
      "FixedFunctionTransformRcPtr")
      .smartptr_to<OCIO_NAMESPACE::FixedFunctionTransform>()
      .m(&OCIO_NAMESPACE::FixedFunctionTransformRcPtr::get);
  bbl::Class<OCIO_NAMESPACE::ConstFixedFunctionTransformRcPtr>(
      "ConstFixedFunctionTransformRcPtr")
      .smartptr_to<OCIO_NAMESPACE::FixedFunctionTransform const>()
      .m(&OCIO_NAMESPACE::ConstFixedFunctionTransformRcPtr::get);

  bbl::Class<OCIO_NAMESPACE::GradingPrimaryTransform>()
      .m((OCIO_NAMESPACE::GradingPrimaryTransformRcPtr(*)(
             OCIO_NAMESPACE::GradingStyle)) &
         OCIO_NAMESPACE::GradingPrimaryTransform::Create)
      .m((OCIO_NAMESPACE::FormatMetadata &
          (OCIO_NAMESPACE::GradingPrimaryTransform::*)()) &
         OCIO_NAMESPACE::GradingPrimaryTransform::getFormatMetadata)
      .m((OCIO_NAMESPACE::FormatMetadata const &(
             OCIO_NAMESPACE::GradingPrimaryTransform::*)() const) &
             OCIO_NAMESPACE::GradingPrimaryTransform::getFormatMetadata,
         "getFormatMetadata_const")
      .m(&OCIO_NAMESPACE::GradingPrimaryTransform::equals)
      .m(&OCIO_NAMESPACE::GradingPrimaryTransform::createEditableCopy)
      .m(&OCIO_NAMESPACE::GradingPrimaryTransform::getDirection)
      .m(&OCIO_NAMESPACE::GradingPrimaryTransform::setDirection)
      .m(&OCIO_NAMESPACE::GradingPrimaryTransform::getTransformType)
      .m(&OCIO_NAMESPACE::GradingPrimaryTransform::validate)
      .m(&OCIO_NAMESPACE::GradingPrimaryTransform::getStyle)
      .m(&OCIO_NAMESPACE::GradingPrimaryTransform::setStyle)
      .m(&OCIO_NAMESPACE::GradingPrimaryTransform::getValue)
      .m(&OCIO_NAMESPACE::GradingPrimaryTransform::setValue)
      .m(&OCIO_NAMESPACE::GradingPrimaryTransform::isDynamic)
      .m(&OCIO_NAMESPACE::GradingPrimaryTransform::makeDynamic)
      .m(&OCIO_NAMESPACE::GradingPrimaryTransform::makeNonDynamic);

  bbl::Class<OCIO_NAMESPACE::GradingPrimaryTransformRcPtr>(
      "GradingPrimaryTransformRcPtr")
      .smartptr_to<OCIO_NAMESPACE::GradingPrimaryTransform>()
      .m(&OCIO_NAMESPACE::GradingPrimaryTransformRcPtr::get);
  bbl::Class<OCIO_NAMESPACE::ConstGradingPrimaryTransformRcPtr>(
      "ConstGradingPrimaryTransformRcPtr")
      .smartptr_to<OCIO_NAMESPACE::GradingPrimaryTransform const>()
      .m(&OCIO_NAMESPACE::ConstGradingPrimaryTransformRcPtr::get);

  bbl::Class<OCIO_NAMESPACE::GradingRGBCurveTransform>()
      .m((OCIO_NAMESPACE::GradingRGBCurveTransformRcPtr(*)(
             OCIO_NAMESPACE::GradingStyle)) &
         OCIO_NAMESPACE::GradingRGBCurveTransform::Create)
      .m((OCIO_NAMESPACE::FormatMetadata &
          (OCIO_NAMESPACE::GradingRGBCurveTransform::*)()) &
         OCIO_NAMESPACE::GradingRGBCurveTransform::getFormatMetadata)
      .m((OCIO_NAMESPACE::FormatMetadata const &(
             OCIO_NAMESPACE::GradingRGBCurveTransform::*)() const) &
             OCIO_NAMESPACE::GradingRGBCurveTransform::getFormatMetadata,
         "getFormatMetadata_const")
      .m(&OCIO_NAMESPACE::GradingRGBCurveTransform::equals)
      .m(&OCIO_NAMESPACE::GradingRGBCurveTransform::createEditableCopy)
      .m(&OCIO_NAMESPACE::GradingRGBCurveTransform::getDirection)
      .m(&OCIO_NAMESPACE::GradingRGBCurveTransform::setDirection)
      .m(&OCIO_NAMESPACE::GradingRGBCurveTransform::getTransformType)
      .m(&OCIO_NAMESPACE::GradingRGBCurveTransform::validate)
      .m(&OCIO_NAMESPACE::GradingRGBCurveTransform::getStyle)
      .m(&OCIO_NAMESPACE::GradingRGBCurveTransform::setStyle)
      .m(&OCIO_NAMESPACE::GradingRGBCurveTransform::getValue)
      .m(&OCIO_NAMESPACE::GradingRGBCurveTransform::setValue)
      .m(&OCIO_NAMESPACE::GradingRGBCurveTransform::getSlope)
      .m(&OCIO_NAMESPACE::GradingRGBCurveTransform::setSlope)
      .m(&OCIO_NAMESPACE::GradingRGBCurveTransform::slopesAreDefault)
      .m(&OCIO_NAMESPACE::GradingRGBCurveTransform::getBypassLinToLog)
      .m(&OCIO_NAMESPACE::GradingRGBCurveTransform::setBypassLinToLog)
      .m(&OCIO_NAMESPACE::GradingRGBCurveTransform::isDynamic)
      .m(&OCIO_NAMESPACE::GradingRGBCurveTransform::makeDynamic)
      .m(&OCIO_NAMESPACE::GradingRGBCurveTransform::makeNonDynamic);

  bbl::Class<OCIO_NAMESPACE::GradingRGBCurveTransformRcPtr>(
      "GradingRGBCurveTransformRcPtr")
      .smartptr_to<OCIO_NAMESPACE::GradingRGBCurveTransform>()
      .m(&OCIO_NAMESPACE::GradingRGBCurveTransformRcPtr::get);
  bbl::Class<OCIO_NAMESPACE::ConstGradingRGBCurveTransformRcPtr>(
      "ConstGradingRGBCurveTransformRcPtr")
      .smartptr_to<OCIO_NAMESPACE::GradingRGBCurveTransform const>()
      .m(&OCIO_NAMESPACE::ConstGradingRGBCurveTransformRcPtr::get);

  bbl::Class<OCIO_NAMESPACE::GradingToneTransform>()
      .m((OCIO_NAMESPACE::GradingToneTransformRcPtr(*)(
             OCIO_NAMESPACE::GradingStyle)) &
         OCIO_NAMESPACE::GradingToneTransform::Create)
      .m((OCIO_NAMESPACE::FormatMetadata &
          (OCIO_NAMESPACE::GradingToneTransform::*)()) &
         OCIO_NAMESPACE::GradingToneTransform::getFormatMetadata)
      .m((OCIO_NAMESPACE::FormatMetadata const &(
             OCIO_NAMESPACE::GradingToneTransform::*)() const) &
             OCIO_NAMESPACE::GradingToneTransform::getFormatMetadata,
         "getFormatMetadata_const")
      .m(&OCIO_NAMESPACE::GradingToneTransform::equals)
      .m(&OCIO_NAMESPACE::GradingToneTransform::createEditableCopy)
      .m(&OCIO_NAMESPACE::GradingToneTransform::getDirection)
      .m(&OCIO_NAMESPACE::GradingToneTransform::setDirection)
      .m(&OCIO_NAMESPACE::GradingToneTransform::getTransformType)
      .m(&OCIO_NAMESPACE::GradingToneTransform::validate)
      .m(&OCIO_NAMESPACE::GradingToneTransform::getStyle)
      .m(&OCIO_NAMESPACE::GradingToneTransform::setStyle)
      .m(&OCIO_NAMESPACE::GradingToneTransform::getValue)
      .m(&OCIO_NAMESPACE::GradingToneTransform::setValue)
      .m(&OCIO_NAMESPACE::GradingToneTransform::isDynamic)
      .m(&OCIO_NAMESPACE::GradingToneTransform::makeDynamic)
      .m(&OCIO_NAMESPACE::GradingToneTransform::makeNonDynamic);

  bbl::Class<OCIO_NAMESPACE::GradingToneTransformRcPtr>(
      "GradingToneTransformRcPtr")
      .smartptr_to<OCIO_NAMESPACE::GradingToneTransform>()
      .m(&OCIO_NAMESPACE::GradingToneTransformRcPtr::get);
  bbl::Class<OCIO_NAMESPACE::ConstGradingToneTransformRcPtr>(
      "ConstGradingToneTransformRcPtr")
      .smartptr_to<OCIO_NAMESPACE::GradingToneTransform const>()
      .m(&OCIO_NAMESPACE::ConstGradingToneTransformRcPtr::get);

  bbl::Enum<OCIO_NAMESPACE::ExposureContrastStyle>().prefix("");

  bbl::Class<OCIO_NAMESPACE::GradingRGBM>()
      .value_type()
      .f(&OCIO_NAMESPACE::GradingRGBM::m_red)
      .f(&OCIO_NAMESPACE::GradingRGBM::m_green)
      .f(&OCIO_NAMESPACE::GradingRGBM::m_blue)
      .f(&OCIO_NAMESPACE::GradingRGBM::m_master);

  bbl::Class<OCIO_NAMESPACE::GradingPrimary>()
      .value_type()
      .ctor(bbl::Ctor<OCIO_NAMESPACE::GradingPrimary,
                      OCIO_NAMESPACE::GradingStyle>("gradingStyle"),
            "default")
      .f(&OCIO_NAMESPACE::GradingPrimary::m_brightness)
      .f(&OCIO_NAMESPACE::GradingPrimary::m_contrast)
      .f(&OCIO_NAMESPACE::GradingPrimary::m_gamma)
      .f(&OCIO_NAMESPACE::GradingPrimary::m_offset)
      .f(&OCIO_NAMESPACE::GradingPrimary::m_exposure)
      .f(&OCIO_NAMESPACE::GradingPrimary::m_lift)
      .f(&OCIO_NAMESPACE::GradingPrimary::m_gain)
      .f(&OCIO_NAMESPACE::GradingPrimary::m_saturation)
      .f(&OCIO_NAMESPACE::GradingPrimary::m_pivot)
      .f(&OCIO_NAMESPACE::GradingPrimary::m_pivotBlack)
      .f(&OCIO_NAMESPACE::GradingPrimary::m_pivotWhite)
      .f(&OCIO_NAMESPACE::GradingPrimary::m_clampBlack)
      .f(&OCIO_NAMESPACE::GradingPrimary::m_clampWhite)
      .m(&OCIO_NAMESPACE::GradingPrimary::validate)
      .m(&OCIO_NAMESPACE::GradingPrimary::NoClampWhite)
      .m(&OCIO_NAMESPACE::GradingPrimary::NoClampBlack);

  bbl::Enum<OCIO_NAMESPACE::GradingStyle>().prefix("");

  bbl::Class<OCIO_NAMESPACE::GradingControlPoint>()
      .value_type()
      .f(&OCIO_NAMESPACE::GradingControlPoint::m_x)
      .f(&OCIO_NAMESPACE::GradingControlPoint::m_y);

  bbl::Class<OCIO_NAMESPACE::GradingBSplineCurve>()
      .m((OCIO_NAMESPACE::GradingBSplineCurveRcPtr(*)(size_t)) &
         OCIO_NAMESPACE::GradingBSplineCurve::Create)
      .m(&OCIO_NAMESPACE::GradingBSplineCurve::createEditableCopy)
      .m(&OCIO_NAMESPACE::GradingBSplineCurve::getNumControlPoints)
      .m(&OCIO_NAMESPACE::GradingBSplineCurve::setNumControlPoints)
      .m((OCIO_NAMESPACE::GradingControlPoint &
          (OCIO_NAMESPACE::GradingBSplineCurve::*)(size_t)) &
         OCIO_NAMESPACE::GradingBSplineCurve::getControlPoint)
      .m((OCIO_NAMESPACE::GradingControlPoint const &(
             OCIO_NAMESPACE::GradingBSplineCurve::*)(size_t) const) &
             OCIO_NAMESPACE::GradingBSplineCurve::getControlPoint,
         "getControlPoint_const")
      .m(&OCIO_NAMESPACE::GradingBSplineCurve::getSlope)
      .m(&OCIO_NAMESPACE::GradingBSplineCurve::setSlope)
      .m(&OCIO_NAMESPACE::GradingBSplineCurve::slopesAreDefault)
      .m(&OCIO_NAMESPACE::GradingBSplineCurve::validate);

  bbl::Class<OCIO_NAMESPACE::GradingBSplineCurveRcPtr>(
      "GradingBSplineCurveRcPtr")
      .smartptr_to<OCIO_NAMESPACE::GradingBSplineCurve>()
      .m(&OCIO_NAMESPACE::GradingBSplineCurveRcPtr::get);
  bbl::Class<OCIO_NAMESPACE::ConstGradingBSplineCurveRcPtr>(
      "ConstGradingBSplineCurveRcPtr")
      .smartptr_to<OCIO_NAMESPACE::GradingBSplineCurve const>()
      .m(&OCIO_NAMESPACE::ConstGradingBSplineCurveRcPtr::get);

  bbl::Class<OCIO_NAMESPACE::GradingRGBCurve>()
      .m((OCIO_NAMESPACE::GradingRGBCurveRcPtr(*)(
             OCIO_NAMESPACE::GradingStyle)) &
             OCIO_NAMESPACE::GradingRGBCurve::Create,
         "Create_default")
      .m((OCIO_NAMESPACE::GradingRGBCurveRcPtr(*)(
             OCIO_NAMESPACE::ConstGradingBSplineCurveRcPtr const &,
             OCIO_NAMESPACE::ConstGradingBSplineCurveRcPtr const &,
             OCIO_NAMESPACE::ConstGradingBSplineCurveRcPtr const &,
             OCIO_NAMESPACE::ConstGradingBSplineCurveRcPtr const &)) &
             OCIO_NAMESPACE::GradingRGBCurve::Create,
         "Create")
      .m(&OCIO_NAMESPACE::GradingRGBCurve::createEditableCopy)
      .m(&OCIO_NAMESPACE::GradingRGBCurve::validate)
      .m(&OCIO_NAMESPACE::GradingRGBCurve::isIdentity)
      .m((OCIO_NAMESPACE::ConstGradingBSplineCurveRcPtr(
             OCIO_NAMESPACE::GradingRGBCurve::*)(OCIO_NAMESPACE::RGBCurveType)
              const) &
             OCIO_NAMESPACE::GradingRGBCurve::getCurve,
         "getCurve_const")
      .m((OCIO_NAMESPACE::GradingBSplineCurveRcPtr(
             OCIO_NAMESPACE::GradingRGBCurve::*)(
             OCIO_NAMESPACE::RGBCurveType)) &
             OCIO_NAMESPACE::GradingRGBCurve::getCurve,
         "getCurve");

  bbl::Class<OCIO_NAMESPACE::GradingRGBCurveRcPtr>("GradingRGBCurveRcPtr")
      .smartptr_to<OCIO_NAMESPACE::GradingRGBCurve>()
      .m(&OCIO_NAMESPACE::GradingRGBCurveRcPtr::get);
  bbl::Class<OCIO_NAMESPACE::ConstGradingRGBCurveRcPtr>(
      "ConstGradingRGBCurveRcPtr")
      .smartptr_to<OCIO_NAMESPACE::GradingRGBCurve const>()
      .m(&OCIO_NAMESPACE::ConstGradingRGBCurveRcPtr::get);

  bbl::Class<OCIO_NAMESPACE::GradingRGBMSW>()
      .value_type()
      .ctor(bbl::Ctor<OCIO_NAMESPACE::GradingRGBMSW, double, double, double,
                      double, double, double>("red", "green", "blue", "master",
                                              "start", "width"),
            "from_coeffs")
      .f(&OCIO_NAMESPACE::GradingRGBMSW::m_red)
      .f(&OCIO_NAMESPACE::GradingRGBMSW::m_green)
      .f(&OCIO_NAMESPACE::GradingRGBMSW::m_blue)
      .f(&OCIO_NAMESPACE::GradingRGBMSW::m_master)
      .f(&OCIO_NAMESPACE::GradingRGBMSW::m_start)
      .f(&OCIO_NAMESPACE::GradingRGBMSW::m_width);

  bbl::Class<OCIO_NAMESPACE::GradingTone>()
      .value_type()
      .ctor(
          bbl::Ctor<OCIO_NAMESPACE::GradingTone, OCIO_NAMESPACE::GradingStyle>(
              "style"),
          "default")
      .f(&OCIO_NAMESPACE::GradingTone::m_blacks)
      .f(&OCIO_NAMESPACE::GradingTone::m_shadows)
      .f(&OCIO_NAMESPACE::GradingTone::m_midtones)
      .f(&OCIO_NAMESPACE::GradingTone::m_highlights)
      .f(&OCIO_NAMESPACE::GradingTone::m_whites)
      .f(&OCIO_NAMESPACE::GradingTone::m_scontrast)
      .m(&OCIO_NAMESPACE::GradingTone::validate);

  bbl::Class<OCIO_NAMESPACE::GroupTransform>()
      .m(&OCIO_NAMESPACE::GroupTransform::Create)
      .m((OCIO_NAMESPACE::FormatMetadata &
          (OCIO_NAMESPACE::GroupTransform::*)()) &
         OCIO_NAMESPACE::GroupTransform::getFormatMetadata)
      .m((OCIO_NAMESPACE::FormatMetadata const &(
             OCIO_NAMESPACE::GroupTransform::*)() const) &
             OCIO_NAMESPACE::GroupTransform::getFormatMetadata,
         "getFormatMetadata_const")
      .m(&OCIO_NAMESPACE::GroupTransform::createEditableCopy)
      .m(&OCIO_NAMESPACE::GroupTransform::getDirection)
      .m(&OCIO_NAMESPACE::GroupTransform::setDirection)
      .m(&OCIO_NAMESPACE::GroupTransform::getTransformType)
      .m(&OCIO_NAMESPACE::GroupTransform::validate)
      .m((OCIO_NAMESPACE::ConstTransformRcPtr(
             OCIO_NAMESPACE::GroupTransform::*)(int) const) &
             OCIO_NAMESPACE::GroupTransform::getTransform,
         "getTransform_const")
      .m((OCIO_NAMESPACE::TransformRcPtr &
          (OCIO_NAMESPACE::GroupTransform::*)(int)) &
         OCIO_NAMESPACE::GroupTransform::getTransform)
      .m(&OCIO_NAMESPACE::GroupTransform::appendTransform)
      .m(&OCIO_NAMESPACE::GroupTransform::prependTransform)
      .m(&OCIO_NAMESPACE::GroupTransform::write)
      .m(&OCIO_NAMESPACE::GroupTransform::GetNumWriteFormats)
      .m(&OCIO_NAMESPACE::GroupTransform::GetFormatNameByIndex)
      .m(&OCIO_NAMESPACE::GroupTransform::GetFormatExtensionByIndex);

  bbl::Class<OCIO_NAMESPACE::GroupTransformRcPtr>("GroupTransformRcPtr")
      .smartptr_to<OCIO_NAMESPACE::GroupTransform>()
      .m(&OCIO_NAMESPACE::GroupTransformRcPtr::get);
  bbl::Class<OCIO_NAMESPACE::ConstGroupTransformRcPtr>(
      "ConstGroupTransformRcPtr")
      .smartptr_to<OCIO_NAMESPACE::GroupTransform const>()
      .m(&OCIO_NAMESPACE::ConstGroupTransformRcPtr::get);

  bbl::Class<OCIO_NAMESPACE::LogAffineTransform>()
      .m(&OCIO_NAMESPACE::LogAffineTransform::Create)
      .m((OCIO_NAMESPACE::FormatMetadata &
          (OCIO_NAMESPACE::LogAffineTransform::*)()) &
         OCIO_NAMESPACE::LogAffineTransform::getFormatMetadata)
      .m((OCIO_NAMESPACE::FormatMetadata const &(
             OCIO_NAMESPACE::LogAffineTransform::*)() const) &
             OCIO_NAMESPACE::LogAffineTransform::getFormatMetadata,
         "getFormatMetadata_const")
      .m(&OCIO_NAMESPACE::LogAffineTransform::equals)
      .m(&OCIO_NAMESPACE::LogAffineTransform::createEditableCopy)
      .m(&OCIO_NAMESPACE::LogAffineTransform::getDirection)
      .m(&OCIO_NAMESPACE::LogAffineTransform::setDirection)
      .m(&OCIO_NAMESPACE::LogAffineTransform::getTransformType)
      .m(&OCIO_NAMESPACE::LogAffineTransform::validate)
      .m(&OCIO_NAMESPACE::LogAffineTransform::getBase)
      .m(&OCIO_NAMESPACE::LogAffineTransform::setBase)
      .m(&OCIO_NAMESPACE::LogAffineTransform::getLogSideSlopeValue)
      .m(&OCIO_NAMESPACE::LogAffineTransform::setLogSideSlopeValue)
      .m(&OCIO_NAMESPACE::LogAffineTransform::getLogSideOffsetValue)
      .m(&OCIO_NAMESPACE::LogAffineTransform::getLinSideSlopeValue)
      .m(&OCIO_NAMESPACE::LogAffineTransform::setLinSideSlopeValue)
      .m(&OCIO_NAMESPACE::LogAffineTransform::getLinSideOffsetValue)
      .m(&OCIO_NAMESPACE::LogAffineTransform::setLinSideOffsetValue)
      ;

  bbl::Class<OCIO_NAMESPACE::LogAffineTransformRcPtr>("LogAffineTransformRcPtr")
      .smartptr_to<OCIO_NAMESPACE::LogAffineTransform>()
      .m(&OCIO_NAMESPACE::LogAffineTransformRcPtr::get);
  bbl::Class<OCIO_NAMESPACE::ConstLogAffineTransformRcPtr>(
      "ConstLogAffineTransformRcPtr")
      .smartptr_to<OCIO_NAMESPACE::LogAffineTransform const>()
      .m(&OCIO_NAMESPACE::ConstLogAffineTransformRcPtr::get);

  bbl::Class<OCIO_NAMESPACE::LogCameraTransform>()
      .m(&OCIO_NAMESPACE::LogCameraTransform::Create)
      .m((OCIO_NAMESPACE::FormatMetadata &
          (OCIO_NAMESPACE::LogCameraTransform::*)()) &
         OCIO_NAMESPACE::LogCameraTransform::getFormatMetadata)
      .m((OCIO_NAMESPACE::FormatMetadata const &(
             OCIO_NAMESPACE::LogCameraTransform::*)() const) &
             OCIO_NAMESPACE::LogCameraTransform::getFormatMetadata,
         "getFormatMetadata_const")
      .m(&OCIO_NAMESPACE::LogCameraTransform::equals)
      .m(&OCIO_NAMESPACE::LogCameraTransform::createEditableCopy)
      .m(&OCIO_NAMESPACE::LogCameraTransform::getDirection)
      .m(&OCIO_NAMESPACE::LogCameraTransform::setDirection)
      .m(&OCIO_NAMESPACE::LogCameraTransform::getTransformType)
      .m(&OCIO_NAMESPACE::LogCameraTransform::validate)
      .m(&OCIO_NAMESPACE::LogCameraTransform::getBase)
      .m(&OCIO_NAMESPACE::LogCameraTransform::setBase)
      .m(&OCIO_NAMESPACE::LogCameraTransform::getLogSideSlopeValue)
      .m(&OCIO_NAMESPACE::LogCameraTransform::setLogSideSlopeValue)
      .m(&OCIO_NAMESPACE::LogCameraTransform::getLogSideOffsetValue)
      .m(&OCIO_NAMESPACE::LogCameraTransform::getLinSideSlopeValue)
      .m(&OCIO_NAMESPACE::LogCameraTransform::setLinSideSlopeValue)
      .m(&OCIO_NAMESPACE::LogCameraTransform::getLinSideOffsetValue)
      .m(&OCIO_NAMESPACE::LogCameraTransform::setLinSideOffsetValue)
      .m(&OCIO_NAMESPACE::LogCameraTransform::getLinSideBreakValue)
      .m(&OCIO_NAMESPACE::LogCameraTransform::setLinSideBreakValue)
      .m(&OCIO_NAMESPACE::LogCameraTransform::getLinearSlopeValue)
      .m(&OCIO_NAMESPACE::LogCameraTransform::setLinearSlopeValue)
      .m(&OCIO_NAMESPACE::LogCameraTransform::unsetLinearSlopeValue)
      ;

  bbl::Class<OCIO_NAMESPACE::LogCameraTransformRcPtr>("LogCameraTransformRcPtr")
      .smartptr_to<OCIO_NAMESPACE::LogCameraTransform>()
      .m(&OCIO_NAMESPACE::LogCameraTransformRcPtr::get);
  bbl::Class<OCIO_NAMESPACE::ConstLogCameraTransformRcPtr>(
      "ConstLogCameraTransformRcPtr")
      .smartptr_to<OCIO_NAMESPACE::LogCameraTransform const>()
      .m(&OCIO_NAMESPACE::ConstLogCameraTransformRcPtr::get);

  bbl::Class<OCIO_NAMESPACE::LogTransform>()
      .m(&OCIO_NAMESPACE::LogTransform::Create)
      .m((OCIO_NAMESPACE::FormatMetadata &
          (OCIO_NAMESPACE::LogTransform::*)()) &
         OCIO_NAMESPACE::LogTransform::getFormatMetadata)
      .m((OCIO_NAMESPACE::FormatMetadata const &(
             OCIO_NAMESPACE::LogTransform::*)() const) &
             OCIO_NAMESPACE::LogTransform::getFormatMetadata,
         "getFormatMetadata_const")
      .m(&OCIO_NAMESPACE::LogTransform::equals)
      .m(&OCIO_NAMESPACE::LogTransform::createEditableCopy)
      .m(&OCIO_NAMESPACE::LogTransform::getDirection)
      .m(&OCIO_NAMESPACE::LogTransform::setDirection)
      .m(&OCIO_NAMESPACE::LogTransform::getTransformType)
      .m(&OCIO_NAMESPACE::LogTransform::validate)
      .m(&OCIO_NAMESPACE::LogTransform::getBase)
      .m(&OCIO_NAMESPACE::LogTransform::setBase);

  bbl::Class<OCIO_NAMESPACE::LogTransformRcPtr>("LogTransformRcPtr")
      .smartptr_to<OCIO_NAMESPACE::LogTransform>()
      .m(&OCIO_NAMESPACE::LogTransformRcPtr::get);
  bbl::Class<OCIO_NAMESPACE::ConstLogTransformRcPtr>("ConstLogTransformRcPtr")
      .smartptr_to<OCIO_NAMESPACE::LogTransform const>()
      .m(&OCIO_NAMESPACE::ConstLogTransformRcPtr::get);

  bbl::Class<OCIO_NAMESPACE::LookTransform>()
      .m(&OCIO_NAMESPACE::LookTransform::Create)
      .m(&OCIO_NAMESPACE::LookTransform::createEditableCopy)
      .m(&OCIO_NAMESPACE::LookTransform::getDirection)
      .m(&OCIO_NAMESPACE::LookTransform::setDirection)
      .m(&OCIO_NAMESPACE::LookTransform::getTransformType)
      .m(&OCIO_NAMESPACE::LookTransform::validate)
      .m(&OCIO_NAMESPACE::LookTransform::getSrc)
      .m(&OCIO_NAMESPACE::LookTransform::setSrc)
      .m(&OCIO_NAMESPACE::LookTransform::getDst)
      .m(&OCIO_NAMESPACE::LookTransform::setDst)
      .m(&OCIO_NAMESPACE::LookTransform::getLooks)
      .m(&OCIO_NAMESPACE::LookTransform::setLooks)
      .m(&OCIO_NAMESPACE::LookTransform::getSkipColorSpaceConversion)
      .m(&OCIO_NAMESPACE::LookTransform::setSkipColorSpaceConversion)
      .m(&OCIO_NAMESPACE::LookTransform::GetLooksResultColorSpace);

  bbl::Class<OCIO_NAMESPACE::LookTransformRcPtr>("LookTransformRcPtr")
      .smartptr_to<OCIO_NAMESPACE::LookTransform>()
      .m(&OCIO_NAMESPACE::LookTransformRcPtr::get);
  bbl::Class<OCIO_NAMESPACE::ConstLookTransformRcPtr>("ConstLookTransformRcPtr")
      .smartptr_to<OCIO_NAMESPACE::LookTransform const>()
      .m(&OCIO_NAMESPACE::ConstLookTransformRcPtr::get);

  bbl::Enum<OCIO_NAMESPACE::Lut1DHueAdjust>().prefix("");

  bbl::Class<OCIO_NAMESPACE::Lut1DTransform>()
      .m((OCIO_NAMESPACE::Lut1DTransformRcPtr(*)()) &
         OCIO_NAMESPACE::Lut1DTransform::Create)
      .m((OCIO_NAMESPACE::Lut1DTransformRcPtr(*)(unsigned long, bool)) &
             OCIO_NAMESPACE::Lut1DTransform::Create,
         "Create_with_length")
      .m((OCIO_NAMESPACE::FormatMetadata &
          (OCIO_NAMESPACE::Lut1DTransform::*)()) &
         OCIO_NAMESPACE::Lut1DTransform::getFormatMetadata)
      .m((OCIO_NAMESPACE::FormatMetadata const &(
             OCIO_NAMESPACE::Lut1DTransform::*)() const) &
             OCIO_NAMESPACE::Lut1DTransform::getFormatMetadata,
         "getFormatMetadata_const")
      .m(&OCIO_NAMESPACE::Lut1DTransform::createEditableCopy)
      .m(&OCIO_NAMESPACE::Lut1DTransform::getDirection)
      .m(&OCIO_NAMESPACE::Lut1DTransform::setDirection)
      .m(&OCIO_NAMESPACE::Lut1DTransform::getTransformType)
      .m(&OCIO_NAMESPACE::Lut1DTransform::validate)
      .m(&OCIO_NAMESPACE::Lut1DTransform::getFileOutputBitDepth)
      .m(&OCIO_NAMESPACE::Lut1DTransform::setFileOutputBitDepth)
      .m(&OCIO_NAMESPACE::Lut1DTransform::getLength)
      .m(&OCIO_NAMESPACE::Lut1DTransform::setLength)
      .m(&OCIO_NAMESPACE::Lut1DTransform::getValue)
      .m(&OCIO_NAMESPACE::Lut1DTransform::setValue)
      .m(&OCIO_NAMESPACE::Lut1DTransform::getInputHalfDomain)
      .m(&OCIO_NAMESPACE::Lut1DTransform::setInputHalfDomain)
      .m(&OCIO_NAMESPACE::Lut1DTransform::getOutputRawHalfs)
      .m(&OCIO_NAMESPACE::Lut1DTransform::setOutputRawHalfs)
      .m(&OCIO_NAMESPACE::Lut1DTransform::getHueAdjust)
      .m(&OCIO_NAMESPACE::Lut1DTransform::setHueAdjust)
      .m(&OCIO_NAMESPACE::Lut1DTransform::getInterpolation)
      .m(&OCIO_NAMESPACE::Lut1DTransform::setInterpolation);

  bbl::Class<OCIO_NAMESPACE::Lut1DTransformRcPtr>("Lut1DTransformRcPtr")
      .smartptr_to<OCIO_NAMESPACE::Lut1DTransform>()
      .m(&OCIO_NAMESPACE::Lut1DTransformRcPtr::get);
  bbl::Class<OCIO_NAMESPACE::ConstLut1DTransformRcPtr>(
      "ConstLut1DTransformRcPtr")
      .smartptr_to<OCIO_NAMESPACE::Lut1DTransform const>()
      .m(&OCIO_NAMESPACE::ConstLut1DTransformRcPtr::get);

  bbl::Class<OCIO_NAMESPACE::Lut3DTransform>()
      .m((OCIO_NAMESPACE::Lut3DTransformRcPtr(*)()) &
         OCIO_NAMESPACE::Lut3DTransform::Create)
      .m((OCIO_NAMESPACE::Lut3DTransformRcPtr(*)(unsigned long)) &
             OCIO_NAMESPACE::Lut3DTransform::Create,
         "Create_with_size")
      .m((OCIO_NAMESPACE::FormatMetadata &
          (OCIO_NAMESPACE::Lut3DTransform::*)()) &
         OCIO_NAMESPACE::Lut3DTransform::getFormatMetadata)
      .m((OCIO_NAMESPACE::FormatMetadata const &(
             OCIO_NAMESPACE::Lut3DTransform::*)() const) &
             OCIO_NAMESPACE::Lut3DTransform::getFormatMetadata,
         "getFormatMetadata_const")
      .m(&OCIO_NAMESPACE::Lut3DTransform::createEditableCopy)
      .m(&OCIO_NAMESPACE::Lut3DTransform::getDirection)
      .m(&OCIO_NAMESPACE::Lut3DTransform::setDirection)
      .m(&OCIO_NAMESPACE::Lut3DTransform::getTransformType)
      .m(&OCIO_NAMESPACE::Lut3DTransform::validate)
      .m(&OCIO_NAMESPACE::Lut3DTransform::getFileOutputBitDepth)
      .m(&OCIO_NAMESPACE::Lut3DTransform::setFileOutputBitDepth)
      .m(&OCIO_NAMESPACE::Lut3DTransform::getGridSize)
      .m(&OCIO_NAMESPACE::Lut3DTransform::setGridSize)
      .m(&OCIO_NAMESPACE::Lut3DTransform::getValue)
      .m(&OCIO_NAMESPACE::Lut3DTransform::setValue)
      .m(&OCIO_NAMESPACE::Lut3DTransform::getInterpolation)
      .m(&OCIO_NAMESPACE::Lut3DTransform::setInterpolation);

  bbl::Class<OCIO_NAMESPACE::Lut3DTransformRcPtr>("Lut3DTransformRcPtr")
      .smartptr_to<OCIO_NAMESPACE::Lut3DTransform>()
      .m(&OCIO_NAMESPACE::Lut3DTransformRcPtr::get);

  bbl::Class<OCIO_NAMESPACE::ConstLut3DTransformRcPtr>(
      "ConstLut3DTransformRcPtr")
      .smartptr_to<OCIO_NAMESPACE::Lut3DTransform const>()
      .m(&OCIO_NAMESPACE::ConstLut3DTransformRcPtr::get);

  bbl::Class<OCIO_NAMESPACE::MatrixTransform>()
      .m(&OCIO_NAMESPACE::MatrixTransform::Create)
      .m((OCIO_NAMESPACE::FormatMetadata &
          (OCIO_NAMESPACE::MatrixTransform::*)()) &
         OCIO_NAMESPACE::MatrixTransform::getFormatMetadata)
      .m((OCIO_NAMESPACE::FormatMetadata const &(
             OCIO_NAMESPACE::MatrixTransform::*)() const) &
             OCIO_NAMESPACE::MatrixTransform::getFormatMetadata,
         "getFormatMetadata_const")
      .m(&OCIO_NAMESPACE::MatrixTransform::createEditableCopy)
      .m(&OCIO_NAMESPACE::MatrixTransform::getDirection)
      .m(&OCIO_NAMESPACE::MatrixTransform::setDirection)
      .m(&OCIO_NAMESPACE::MatrixTransform::getTransformType)
      .m(&OCIO_NAMESPACE::MatrixTransform::validate)
      .m(&OCIO_NAMESPACE::MatrixTransform::equals)
      .m(&OCIO_NAMESPACE::MatrixTransform::getMatrix)
      .m(&OCIO_NAMESPACE::MatrixTransform::setMatrix)
      .m(&OCIO_NAMESPACE::MatrixTransform::getOffset)
      .m(&OCIO_NAMESPACE::MatrixTransform::setOffset)
      .m(&OCIO_NAMESPACE::MatrixTransform::getFileInputBitDepth)
      .m(&OCIO_NAMESPACE::MatrixTransform::setFileInputBitDepth)
      .m(&OCIO_NAMESPACE::MatrixTransform::getFileOutputBitDepth)
      .m(&OCIO_NAMESPACE::MatrixTransform::setFileOutputBitDepth)
      .m(&OCIO_NAMESPACE::MatrixTransform::Fit)
      .m(&OCIO_NAMESPACE::MatrixTransform::Identity)
      .m(&OCIO_NAMESPACE::MatrixTransform::Sat)
      .m(&OCIO_NAMESPACE::MatrixTransform::Scale)
      .m(&OCIO_NAMESPACE::MatrixTransform::View)
      ;

  bbl::Class<OCIO_NAMESPACE::MatrixTransformRcPtr>("MatrixTransformRcPtr")
      .smartptr_to<OCIO_NAMESPACE::MatrixTransform>()
      .m(&OCIO_NAMESPACE::MatrixTransformRcPtr::get);

  bbl::Class<OCIO_NAMESPACE::ConstMatrixTransformRcPtr>(
      "ConstMatrixTransformRcPtr")
      .smartptr_to<OCIO_NAMESPACE::MatrixTransform const>()
      .m(&OCIO_NAMESPACE::ConstMatrixTransformRcPtr::get);

  bbl::Class<OCIO_NAMESPACE::RangeTransform>()
      .m(&OCIO_NAMESPACE::RangeTransform::Create)
      .m((OCIO_NAMESPACE::FormatMetadata &
          (OCIO_NAMESPACE::RangeTransform::*)()) &
         OCIO_NAMESPACE::RangeTransform::getFormatMetadata)
      .m((OCIO_NAMESPACE::FormatMetadata const &(
             OCIO_NAMESPACE::RangeTransform::*)() const) &
             OCIO_NAMESPACE::RangeTransform::getFormatMetadata,
         "getFormatMetadata_const")
      .m(&OCIO_NAMESPACE::RangeTransform::createEditableCopy)
      .m(&OCIO_NAMESPACE::RangeTransform::getDirection)
      .m(&OCIO_NAMESPACE::RangeTransform::setDirection)
      .m(&OCIO_NAMESPACE::RangeTransform::getTransformType)
      .m(&OCIO_NAMESPACE::RangeTransform::validate)
      .m(&OCIO_NAMESPACE::RangeTransform::equals)
      .m(&OCIO_NAMESPACE::RangeTransform::getFileInputBitDepth)
      .m(&OCIO_NAMESPACE::RangeTransform::setFileInputBitDepth)
      .m(&OCIO_NAMESPACE::RangeTransform::getFileOutputBitDepth)
      .m(&OCIO_NAMESPACE::RangeTransform::setFileOutputBitDepth)
      .m(&OCIO_NAMESPACE::RangeTransform::getMinInValue)
      .m(&OCIO_NAMESPACE::RangeTransform::setMinInValue)
      .m(&OCIO_NAMESPACE::RangeTransform::hasMinInValue)
      .m(&OCIO_NAMESPACE::RangeTransform::unsetMinInValue)
      .m(&OCIO_NAMESPACE::RangeTransform::getMaxInValue)
      .m(&OCIO_NAMESPACE::RangeTransform::setMaxInValue)
      .m(&OCIO_NAMESPACE::RangeTransform::hasMaxInValue)
      .m(&OCIO_NAMESPACE::RangeTransform::unsetMaxInValue)
      .m(&OCIO_NAMESPACE::RangeTransform::getMinOutValue)
      .m(&OCIO_NAMESPACE::RangeTransform::setMinOutValue)
      .m(&OCIO_NAMESPACE::RangeTransform::hasMinOutValue)
      .m(&OCIO_NAMESPACE::RangeTransform::unsetMinOutValue)
      .m(&OCIO_NAMESPACE::RangeTransform::getMaxOutValue)
      .m(&OCIO_NAMESPACE::RangeTransform::setMaxOutValue)
      .m(&OCIO_NAMESPACE::RangeTransform::hasMaxOutValue)
      .m(&OCIO_NAMESPACE::RangeTransform::unsetMaxOutValue)
      ;

  bbl::Class<OCIO_NAMESPACE::RangeTransformRcPtr>("RangeTransformRcPtr")
      .smartptr_to<OCIO_NAMESPACE::RangeTransform>()
      .m(&OCIO_NAMESPACE::RangeTransformRcPtr::get);

  bbl::Class<OCIO_NAMESPACE::ConstRangeTransformRcPtr>(
      "ConstRangeTransformRcPtr")
      .smartptr_to<OCIO_NAMESPACE::RangeTransform const>()
      .m(&OCIO_NAMESPACE::ConstRangeTransformRcPtr::get);

  bbl::Enum<OCIO_NAMESPACE::NegativeStyle>().prefix("");

  bbl::Enum<OCIO_NAMESPACE::RGBCurveType>().prefix("");
}

#endif