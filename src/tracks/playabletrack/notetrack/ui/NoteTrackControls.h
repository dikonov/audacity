/**********************************************************************

Audacity: A Digital Audio Editor

NoteTrackControls.h

Paul Licameli split from TrackPanel.cpp

**********************************************************************/

#ifndef __AUDACITY_NOTE_TRACK_CONTROLS__
#define __AUDACITY_NOTE_TRACK_CONTROLS__

#include "../../../ui/CommonTrackControls.h" // to inherit

class MuteButtonHandle;
class SoloButtonHandle;
class NoteTrackButtonHandle;
class VelocitySliderHandle;

///////////////////////////////////////////////////////////////////////////////
class NoteTrackControls : public CommonTrackControls
{
   NoteTrackControls(const NoteTrackControls&) = delete;
   NoteTrackControls &operator=(const NoteTrackControls&) = delete;

   std::weak_ptr<MuteButtonHandle> mMuteHandle;
   std::weak_ptr<SoloButtonHandle> mSoloHandle;
   std::weak_ptr<NoteTrackButtonHandle> mClickHandle;
   std::weak_ptr<VelocitySliderHandle> mVelocityHandle;

public:
   explicit
   NoteTrackControls( std::shared_ptr<Track> pTrack )
      : CommonTrackControls( pTrack ) {}
   ~NoteTrackControls();

   std::vector<UIHandlePtr> HitTest
      (const TrackPanelMouseState &state,
       const AudacityProject *pProject) override;

   PopupMenuTable *GetMenuExtension(Track *pTrack) override;

   const TCPLines& GetTCPLines() const override;
};

#endif
