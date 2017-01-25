#include "courtroom.h"

#include "aoapplication.h"
#include "lobby.h"
#include "text_file_functions.h"
#include "path_functions.h"

#include <QDebug>

Courtroom::Courtroom(AOApplication *p_ao_app) : QMainWindow()
{
  ao_app = p_ao_app;

  ui_background = new AOImage(this, ao_app);

  //viewport elements like background, desk, etc.

  ui_ic_chatlog = new QPlainTextEdit(this);

  ui_ms_chatlog = new QPlainTextEdit(this);
  ui_server_chatlog = new QPlainTextEdit(this);


  ui_mute_list = new QListWidget(this);
  ui_area_list = new QListWidget(this);
  ui_music_list = new QListWidget(this);

  ui_ic_chat_message = new QLineEdit(this);

  ui_ooc_chat_message = new QLineEdit(this);
  ui_ooc_chat_name = new QLineEdit(this);

  ui_area_password = new QLineEdit(this);
  ui_music_search = new QLineEdit(this);

  //emote buttons

  ui_emote_left = new AOButton(this, ao_app);
  ui_emote_right = new AOButton(this, ao_app);

  ui_defense_bar = new AOImage(this, ao_app);
  ui_prosecution_bar = new  AOImage(this, ao_app);

  ui_music_label = new QLabel(this);
  ui_sfx_label = new QLabel(this);
  ui_blip_label = new QLabel(this);

  ui_hold_it = new AOButton(this, ao_app);
  ui_objection = new AOButton(this, ao_app);
  ui_take_that = new AOButton(this, ao_app);

  ui_ooc_toggle = new AOButton(this, ao_app);
  ui_witness_testimony = new AOButton(this, ao_app);
  ui_cross_examination = new AOButton(this, ao_app);

  ui_change_character = new AOButton(this, ao_app);
  ui_reload_theme = new AOButton(this, ao_app);
  ui_call_mod = new AOButton(this, ao_app);

  ui_pre = new QCheckBox(this);
  ui_flip = new QCheckBox(this);
  ui_guard = new QCheckBox(this);

  ui_custom_objection = new AOButton(this, ao_app);
  ui_realization = new AOButton(this, ao_app);
  ui_mute = new AOButton(this, ao_app);

  ui_defense_plus = new AOButton(this, ao_app);
  ui_defense_minus = new AOButton(this, ao_app);

  ui_prosecution_plus = new AOButton(this, ao_app);
  ui_prosecution_minus = new AOButton(this, ao_app);

  ui_text_color = new QComboBox(this);

  ui_music_slider = new QSlider(Qt::Horizontal, this);
  ui_music_slider->setRange(0, 100);
  ui_music_slider->setValue(50);

  ui_sfx_slider = new QSlider(Qt::Horizontal, this);
  ui_sfx_slider->setRange(0, 100);
  ui_sfx_slider->setValue(50);

  ui_blip_slider = new QSlider(Qt::Horizontal, this);
  ui_blip_slider->setRange(0, 100);
  ui_blip_slider->setValue(50);

  ui_muted = new AOImage(this, ao_app);

  /////////////char select widgets under here///////////////

  ui_char_select_background = new AOImage(this, ao_app);

  //setting up the grid and positions
  const int base_x_pos{25};
  const int base_y_pos{36};

  const int x_modifier{67};
  int x_mod_count{0};

  const int y_modifier{67};
  int y_mod_count{0};

  for (int n = 0 ; n < 90 ; ++n)
  {
    ui_char_button_list.append(new AOCharButton(ui_char_select_background, ao_app));
  }

  ui_selector = new AOImage(ui_char_select_background, ao_app);

  ui_back_to_lobby = new AOButton(ui_char_select_background, ao_app);

  ui_char_password = new QLineEdit(ui_char_select_background);

  ui_spectator = new AOButton(ui_char_select_background, ao_app);

  connect(ui_change_character, SIGNAL(clicked()), this, SLOT(on_change_character_clicked()));

  connect(ui_reload_theme, SIGNAL(clicked()), this, SLOT(on_reload_theme_clicked()));

  connect(ui_back_to_lobby, SIGNAL(clicked()), this, SLOT(on_back_to_lobby_clicked()));

  connect(ui_spectator, SIGNAL(clicked()), this, SLOT(on_spectator_clicked()));

  set_widgets();
}

void Courtroom::set_widgets()
{
  this->setFixedSize(m_courtroom_width, m_courtroom_height);
  this->setWindowTitle("Attorney Online 2: Server name here");

  ui_background->set_image("courtroombackground.png");
  ui_background->move(0, 0);
  ui_background->resize(m_courtroom_width, m_courtroom_height);

  //viewport elements like background, desk, etc. go here

  set_size_and_pos(ui_ic_chatlog, "ic_chatlog");

  set_size_and_pos(ui_ms_chatlog, "ms_chatlog");

  set_size_and_pos(ui_server_chatlog, "server_chatlog");

  set_size_and_pos(ui_mute_list, "mute_list");
  set_size_and_pos(ui_area_list, "area_list");

  set_size_and_pos(ui_music_list, "music_list");

  set_size_and_pos(ui_ic_chat_message, "ic_chat_message");

  set_size_and_pos(ui_ooc_chat_message, "ooc_chat_message");
  set_size_and_pos(ui_ooc_chat_name, "ooc_chat_name");

  set_size_and_pos(ui_area_password, "area_password");
  set_size_and_pos(ui_music_search, "music_search");

  //emote buttons

  set_size_and_pos(ui_emote_left, "emote_left");
  ui_emote_left->set_image("arrow_left.png");

  set_size_and_pos(ui_emote_right, "emote_right");
  ui_emote_right->set_image("arrow_right.png");

  set_size_and_pos(ui_defense_bar, "defense_bar");
  ui_defense_bar->set_image("defensebar10.png");

  set_size_and_pos(ui_prosecution_bar, "prosecution_bar");
  ui_prosecution_bar->set_image("prosecutionbar10.png");

  set_size_and_pos(ui_music_label, "music_label");
  ui_music_label->setText("Music");
  set_size_and_pos(ui_sfx_label, "sfx_label");
  ui_sfx_label->setText("Sfx");
  set_size_and_pos(ui_blip_label, "blip_label");
  ui_blip_label->setText("Blips");

  set_size_and_pos(ui_hold_it, "hold_it");
  ui_hold_it->set_image("holdit.png");
  set_size_and_pos(ui_objection, "objection");
  ui_objection->set_image("objection.png");
  set_size_and_pos(ui_take_that, "take_that");
  ui_take_that->set_image("takethat.png");

  set_size_and_pos(ui_ooc_toggle, "ooc_toggle");

  set_size_and_pos(ui_witness_testimony, "witness_testimony");
  ui_witness_testimony->set_image("witnesstestimony.png");
  set_size_and_pos(ui_cross_examination, "cross_examination");
  ui_cross_examination->set_image("crossexamination.png");

  set_size_and_pos(ui_change_character, "change_character");
  ui_change_character->setText("Change character");

  set_size_and_pos(ui_reload_theme, "reload_theme");
  ui_reload_theme->setText("Reload theme");

  set_size_and_pos(ui_call_mod, "call_mod");
  ui_call_mod->setText("Call mod");

  set_size_and_pos(ui_pre, "pre");
  ui_pre->setText("Pre");

  set_size_and_pos(ui_flip, "flip");
  ui_flip->setText("Flip");

  set_size_and_pos(ui_guard, "guard");
  ui_guard->setText("Guard");

  set_size_and_pos(ui_custom_objection, "custom_objection");
  ui_custom_objection->set_image("custom.png");

  set_size_and_pos(ui_realization, "realization");
  ui_realization->set_image("realization.png");

  set_size_and_pos(ui_mute, "mute_button");
  ui_mute->set_image("mute.png");

  set_size_and_pos(ui_defense_plus, "defense_plus");
  ui_defense_plus->set_image("defplus.png");

  set_size_and_pos(ui_defense_minus, "defense_minus");
  ui_defense_minus->set_image("defminus.png");

  set_size_and_pos(ui_prosecution_plus, "prosecution_plus");
  ui_prosecution_plus->set_image("proplus.png");

  set_size_and_pos(ui_prosecution_minus, "prosecution_minus");
  ui_prosecution_minus->set_image("prominus.png");

  set_size_and_pos(ui_text_color, "text_color");

  set_size_and_pos(ui_music_slider, "music_slider");
  set_size_and_pos(ui_sfx_slider, "sfx_slider");
  set_size_and_pos(ui_blip_slider, "blip_slider");

  //T0D0: scale this according to ui_ic_chat_message
  //set_size_and_pos(ui_muted, "muted");

  //char select stuff under here

  ui_char_select_background->set_image("charselect_background.png");
  ui_char_select_background->move(0, 0);
  ui_char_select_background->resize(m_courtroom_width, m_courtroom_height);

  //T0D0: uncomment and set position properly
  //QVector<AOCharButton*> ui_char_button_list;

  ui_selector->set_image("selector.png");
  ui_selector->hide();

  ui_back_to_lobby->setText("Back to Lobby");
  set_size_and_pos(ui_back_to_lobby, "back_to_lobby");

  set_size_and_pos(ui_char_password, "char_password");

  ui_spectator->setText("Spectator");
  set_size_and_pos(ui_spectator, "spectator");

}

void Courtroom::set_size_and_pos(QWidget *p_widget, QString p_identifier)
{
  QString design_ini_path = ao_app->get_theme_path() + "courtroom_design.ini";
  QString default_ini_path = ao_app->get_base_path() + "themes/default/courtroom_design.ini";

  pos_size_type design_ini_result = ao_app->get_pos_and_size(p_identifier, design_ini_path);

  if (design_ini_result.width < 0 || design_ini_result.height < 0)
  {
    design_ini_result = ao_app->get_pos_and_size(p_identifier, default_ini_path);

    if (design_ini_result.width < 0 || design_ini_result.height < 0)
    {
      //at this point it's pretty much game over
      //T0D0: add message box
      qDebug() << "CRITICAL ERROR: NO SUITABLE DATA FOR SETTING " << p_identifier;
      ao_app->quit();
    }
  }

  p_widget->move(design_ini_result.x, design_ini_result.y);
  p_widget->resize(design_ini_result.width, design_ini_result.height);
}

void Courtroom::on_change_character_clicked()
{
  ui_char_select_background->show();
}

void Courtroom::on_reload_theme_clicked()
{
  ao_app->set_user_theme();

  set_widgets();
}

void Courtroom::on_back_to_lobby_clicked()
{
  ao_app->construct_lobby();
  ao_app->w_lobby->list_servers();
  ao_app->destruct_courtroom();
}

void Courtroom::on_spectator_clicked()
{
  ui_char_select_background->hide();
}

Courtroom::~Courtroom()
{

}
