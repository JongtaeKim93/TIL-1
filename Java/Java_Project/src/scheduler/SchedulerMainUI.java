package scheduler;

import javax.swing.*;
import javax.swing.table.DefaultTableModel;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class SchedulerMainUI extends Scheduler {
    private Dimension dimension = new Dimension(600, 600);
    private JFrame frame = new JFrame("Scheduler");
    private String header[] = getDays();
    private String contents[][] = new String[24][7];
    private String times[] = getTimes();
    private JLabel currentTime = new JLabel("현재 시간 : ");
    private JButton addBtn = new JButton(getAddSchedule());
    private JButton adjustBtn = new JButton(getDeleteSchedule());
    private JButton deleteBtn = new JButton(getAdjustSchedule());
    private JPanel panel = new JPanel();
    private JPanel panel1 = new JPanel();

    DefaultTableModel model;
    JScrollPane scrollPane;

    public SchedulerMainUI() {
    }

    public void modelUpdate() {
        for (int i=0; i < times.length; i++) {
            contents[i][0] = times[i];
        }

        model = new DefaultTableModel(contents, header);
        JTable table = new JTable(model);
        table.setRowHeight(50);
        scrollPane = new JScrollPane(table);
    }

    public void viewOn() {

        frame.setLocation(600, 200);
        frame.setPreferredSize(dimension);

        modelUpdate();

        currentTime.setHorizontalAlignment(SwingConstants.LEFT);


        ActionListener addListener = new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                addSchedule();
            }
        };
        addBtn.addActionListener(addListener);

        ActionListener adjustListener = new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                adjustSchedule();
            }
        };
        adjustBtn.addActionListener(adjustListener);

        ActionListener deleteListener = new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                deleteSchedule();
            }
        };
        deleteBtn.addActionListener(deleteListener);

        JButton exitBtn = new JButton(getExit());
        ActionListener exitListener = new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                exitScheduler();
            }
        };
        exitBtn.addActionListener(exitListener);


        panel.setLayout(new BoxLayout(panel, BoxLayout.Y_AXIS));
        panel.add(currentTime, BorderLayout.NORTH);
        panel.add(scrollPane, BorderLayout.CENTER);
        panel1.setLayout(new GridLayout(1, 4));
        panel1.add(addBtn);
        panel1.add(adjustBtn);
        panel1.add(deleteBtn);
        panel1.add(exitBtn);
        panel.add(panel1, BorderLayout.SOUTH);

        frame.add(panel, BorderLayout.CENTER);
        frame.pack();
        frame.setVisible(true);
    }

    public void setContents(String[][] contents) {
        this.contents = contents;
    }

    public String[][] getContents() {
        return contents;
    }

    @Override
    public void currentTimeUpdate(){

    }

    @Override
    public void addSchedule() {
        SchedulerAdd schedulerAdd = new SchedulerAdd();
        schedulerAdd.schedulerAddView();
        frame.setVisible(false);
    }

    public int daySearch(String day) {

        String[] days = getDays();
        int check = -1;

        for (int i = 1; i < days.length; i++) {
            if (days[i].equals(day)) {
                check = i;
                break;
            }
        }

        return check;
    }

    public int[] timeSearch(String time) {
        int check[] = new int[]{-1, -1};
        String[] stringTimes = time.split("~");
        String[] timeTokens = getTimesTokens();

        if (stringTimes.length == 2) {
            for (int i = 0; i < timeTokens.length; i++) {
                if (stringTimes[0].equals(timeTokens[i])) {
                    check[0] = i;
                    break;
                }
            }
            for (int i = 0; i < timeTokens.length; i++) {
                if (stringTimes[1].equals(timeTokens[i])) {
                    check[1] = i;
                    break;
                }
            }
        }
        return check;
    }

    public int[] scheduleSearch(String schedule) {
        int check[] = new int[] {-1, -1};
        String[][] beforeSchedule = getContents();

        for(int i=0; i<getHourRows(); i++) {
            for(int j=0; j<getDaysColumns() + 2; j++) {
                if(schedule.equals(beforeSchedule[i][j])) {
                    check[0] = i;
                    check[1] = j;
                    break;
                }
            }
        }
        return check;
    }

    @Override
    public void adjustSchedule() {

    }

    @Override
    public void deleteSchedule() {

    }

    @Override
    public void exitScheduler() {
        System.exit(1);
    }

    @Override
    public String[][] getSchedule() {
        return super.getSchedule();
    }

    @Override
    public void setSchedule(String[][] schedul) {
        super.setSchedule(schedul);
    }

}